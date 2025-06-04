#include "LGraph.h"

LGraph::LGraph(GraphType type, int vertexNum){
    this->gType = type;
    this->vertexNum = vertexNum;
    this->edgeNum = 0;
    for(int i=0;i<vertexNum;i++)
        this->adjlist[i].firstEdge = nullptr;
}
LGraph::~LGraph(){
    for(int i=0;i<this->vertexNum;i++ ){
        PrtEdgeNode curEdge = this->adjlist[i].firstEdge;
        while(curEdge){
            delete curEdge;
            curEdge = curEdge->next;
        }
    }
}

//插入边{v1,v2,weight}
void LGraph::insertEdge(PtrEdge pEdge){
    PrtEdgeNode newNode = new EdgeNode;
    newNode->vertex = pEdge->v2;
    newNode->weight = pEdge->weight;

    //切下与“头节点”的连接，作为新节点的next
    newNode->next = this->adjlist[pEdge->v1].firstEdge;
    //再连接“头结点”与新节点(边的节点)
    this->adjlist[pEdge->v1].firstEdge = newNode;

    //如果是无向图,插入反向的对称一条边
    if(this->gType == UG){
    PrtEdgeNode _newNode = new EdgeNode;
    _newNode->vertex = pEdge->v1;
    _newNode->weight = pEdge->weight;

    //切下与“头节点”的连接，作为新节点的next
    _newNode->next = this->adjlist[pEdge->v2].firstEdge;
    //再连接“头结点”与新节点(边的节点)
    this->adjlist[pEdge->v2].firstEdge = _newNode;
    }
}

//深度优先遍历全图
void LGraph::DFS_LGraph(){
    int i;
    for ( i = 0; i < this->vertexNum; i++ )
        visited[ i ] = false;  //确保开始前都没访问过 

    for ( i = 0; i < this->vertexNum; i++ ){
        if (!visited[i]) // 若i未被访问过
            DFSFromVertex(i); // 从i开始DFS搜索一个连通分量
    }

}

//从点v出发，深度优先递归遍历图(连通分量)
void LGraph::DFSFromVertex(VertexType v){
    EdgeNode *edge;

    visitVertex(v);//访问之
    for(edge = adjlist[v].firstEdge;  edge;  edge = edge->next ) 
        if ( !visited[edge->vertex] )
            DFSFromVertex(edge->vertex);//遍历之
}

//广度优先遍历全图
#include "queue/linked_queue.hpp"//需要借助前面写的队列进行遍历
void LGraph::BFS_LGraph(){
    VertexType i,j;
    PrtEdgeNode k;
    LinkedQueue<VertexType> queue;
    for ( i = 0; i < this->vertexNum; i++ ){
        visited[ i ] = false;  //确保开始前都没访问过 
    }
    for ( i = 0; i<this->vertexNum; ++i )
    if (!visited[i] ) { //没有访问过
        visitVertex(i);  //访问之 
        queue.enqueue(i);//入队
        while (!queue.empty()) {
            j = queue.dequeue();  //出队一个
            
            //把所有与j邻接的点入队
            for( k = adjlist[j].firstEdge;  k;  k = k->next )
                if ( !visited[k->vertex] ) {
                    visitVertex(k->vertex); 
                    queue.enqueue(k->vertex);//入队
                }
        } 
    } 
}



void LGraph::visitVertex(VertexType v){
    //  TODO
    //暂时不需要其他操作
    visited[v] = true; 
}