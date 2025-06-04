#include "MGraph.h"

MGraph::MGraph(GraphType type, int vertexNum)
{
    this->GType = type;
    this->vertexNum = vertexNum;
    this->edgeNum = 0;
}

MGraph::~MGraph() {}

void MGraph::insertEdge(PtrEdge edge)
{

    Edges[edge->v1][edge->v2] = edge->weight;

    //如果是无向图，需要把(v2,v1)也插入
    if (this->GType == UG)
    {
        Edges[edge->v2][edge->v1] = edge->weight;
    }
    this->edgeNum += 1;
}

//迪杰斯特拉算法 求顶点v0到其他点的最短路径P[]和路径长度D[]
void MGraph::dijkstra(int v0, int *P, int *D)
{   //核心: 1、广度优先搜索计算v0到所有邻接点的距离，取距离最小的那个点Vmin放入集合S，
    //     2、从S中取出Vmin,对Vmin进行第一步的算法
    //     3、重复1 2 步骤 直到所有点都在集合S，或者再也找不到联通点
    //这里默认是有向带权无环图 而且权重不能有负值
    int Final[MaxVertexNum], v, w, i, j, min;

    for (v = 0; v < vertexNum; ++v)
    { /* 初始化 */
        Final[v] = false;
        D[v] = this->Edges[v0][v];
        for (w = 0; w < vertexNum; ++w)
            if (D[w] < INFINITY)
                P[w] = v0; /* 设父顶点v0  */
    }
    D[v0] = 0;
    Final[v0] = true; /* 初始状态：v0顶点属于S集 */

    /*开始主循环，每次求得v0到某个v 顶点的最短路径，并加v到集合P */
    for (i = 1; i < vertexNum; ++i)
    {
        min = INFINITY; /* min为当前所知离v0顶点的最近距离 */
        for (w = 0; w < vertexNum; ++w)
            if (!Final[w]) /* w顶点在V－S中 */
                if (D[w] < min)
                {
                    v = w;
                    min = D[w];
                } /* 寻找最短路径顶点v */
        if (min < INFINITY)
            Final[v] = true; //! 重要 离v0顶点最近的v加入S集合
        else
            break;                      /* 否则是非连通图，结束。  */
        for (w = 0; w < vertexNum; ++w) /* 更新当前最短路径*/
            if (!Final[w] && (min + this->Edges[v][w] < D[w]))
            {
                D[w] = min + this->Edges[v][w];
                P[w] = v;
            }
    }
}

void MGraph::floyd(int *P[], int *D[])
{ /*求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w] */
    /*若P[v][w]=u，代表u是从v到w的最短路径必经的顶点。
    核心思想：初始矩阵D(其实就是图邻接矩阵)，最开始D[i][j]代表不用任何点作为中介到达所有点的距离，到自己0，不连通为∞
    1、首先只允许经过第0个点V[0]，如果经过V[0]的中转，使得D[i][j]变短的话，就更新D[i][j]的值为D[i][0]+D[0][j],
       同时更新P[i][j]=0
    2、在第一步的基础上，D变成了只允许经过第0个点V[0]情况的任意两点最短距离矩阵，这时在允许经过第一个点V[1]，如果可以
       使得D[i][j]变短的话，继续更新D[i][j]和P[i][j]，此时D就变成了只允许经过V[0]V[1]两个点的情况下任意两点最短距离
    3、以此类推 0,1,2,3...直到最后一个点V[n-1],矩阵D中就是点与点之间最短路径的值了
    */
    int u, v, w, i;

    for (v = 0; v < this->vertexNum; ++v) /* 各对顶点之间初始已知路径及距离 */
        for (w = 0; w < this->vertexNum; ++w)
        {
            D[v][w] = this->Edges[v][w];
            P[v][w] = v; /* 假设从v到w有直接路径*/
        }                /*如果不存在直接的边，D[v][w] = ∞，P[v][w] = v也不会混淆*/
    for (u = 0; u < this->vertexNum; ++u)
        for (v = 0; v < this->vertexNum; ++v)
            for (w = 0; w < this->vertexNum; ++w)
                if (D[v][u] + D[u][w] < D[v][w])
                {
                    /*从v经u到w的一条路径更短*/
                    D[v][w] = D[v][u] + D[u][w];
                    P[v][w] = u;
                }
}

//* Pareent 表示每个顶点的父节点的最小生成树存于数组Parent中
void MGraph::prim(int Parent[])
{   /* 默认从序号为0的顶点出发 */
    int LowCost[MaxVertexNum];
    int i, j, k;

    for (i = 1; i < vertexNum; i++)
    { /* 初始化 */
        LowCost[i] = this->Edges[0][i];
        Parent[i] = 0; /*暂且认为所有顶点的父节点是 0（根结点）*/
    }
    LowCost[0] = 0; /* 从序号为0的顶点出发生成最小生成树 */
    Parent[0] = -1; /* 生成树的根节点 */
    for (i = 1; i < vertexNum; i++)
    {                                    /* 生长成最小生成树还需要收集n-1个结点 */
        k = findMin(LowCost, vertexNum); /* 求V－VT中到VT最小距离的点k*/
        if (k)
        {                              /* 如果找到 */
            LowCost[k] = 0;            /*  生长至顶点k  */
            for (j = 1; j < vertexNum; j++) /* 更新当前最小生成树*/
                if (LowCost[j] && this->Edges[k][j] < LowCost[j])
                {
                    /* 如果j是V－VT中的顶点且距离需要更新 */
                    LowCost[j] = this->Edges[k][j]; /* 更新最小距离  */
                    Parent[j] = k;               /*  暂且认为顶点j的父结点是 k  */
                }                                /* 结束if需要更新j */
        }                                        /* 结束if找到下一个k */
        else
        { /* 还没收集完所有结点就不能继续生长，一定为非连通图 */
            //printf("图不连通");
            break;
        }
    }
}

int MGraph::findMin(int LowCost[], int n)
{ /* 求V－VT中到VT最小距离的点 */
    int j, k, MinCost = INFINITY;

    for (k = 0, j = 0; j < n; j++)
        if (LowCost[j] && LowCost[j] < MinCost)
        {
            MinCost = LowCost[j];
            k = j;
        }

    return k;
}

//获取所有的顶点的入度，存放在数组inDegree中
//默认inDegree已经初始化 全部为0
void MGraph::getInDegree(int *inDegree)
{   //以有向无权图为例
    for(int i=0;i<vertexNum;i++){
        //邻接矩阵存储，只需要计算第i行有多少不为0的值
        for(int j=0;j<vertexNum;j++){
            if(0 != Edges[i][j]){
                inDegree[i]++;
            }
        }
    }
}

//获取顶点v所有的邻接点
//默认V已经初始化为全0
void MGraph::getAllAdjVertex(VertexType v, int V[]){
//以有向无权图为例
    for(int j=0;j<vertexNum;j++){
        //邻接矩阵存储，只需要计算第i列有多少不为0的值
        for(int i=0;i<vertexNum;i++){
            //有向无权图 要么0(不连通)要么1(连通)
            V[i] = Edges[i][j];
        }
    }
}
