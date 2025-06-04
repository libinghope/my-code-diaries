//使用邻接表来表示图
#define MaxVertexNum 100 //最大顶点数设为100
#define INFINITY 65535   //无穷大设为双字节无符号整数的最大值65535
typedef int VertexType;  //顶点类型设为整型
typedef int WeightType;  //边的权重假定为整型
enum GraphType
{
    DG,//有向图
    UG,//无向图
    DN,//有向网图(边有权重)
    UN //无向网图(边有权重)
};

typedef struct Edge{
    VertexType v1, v2;  //边的两个顶点(v1,v2)或者<v1,v2>
    WeightType weight;  //有向图边的权重
}*PtrEdge;

class MGraph
{
public:
    MGraph(GraphType type, int vertexNum);
    ~MGraph();
    void insertEdge(PtrEdge edge);
    //迪杰斯特拉算法
    void dijkstra(VertexType v0,int *P,int *D);
    //弗洛伊德算法
    void floyd(int *P[], int *D[]);
    //最小生成树 普里姆算法
    void prim(int Parent[]);
    //计算所有顶点的入度
    void getInDegree(int *inDegree);
    //获取顶点V所有的邻接点
    void getAllAdjVertex(VertexType v, int V[]);

    inline int getVertexNum(){return this->vertexNum;}
private:
    //求V－VT中到VT最小距离的点
    int findMin(int LowCost[], int n);

private:
    WeightType Edges[MaxVertexNum][MaxVertexNum]={0}; //邻接矩阵，即边表
    int vertexNum;                                    //顶点个数
    int edgeNum;                                      //边的个数 
    enum GraphType GType;                             //图的类型ß
};
