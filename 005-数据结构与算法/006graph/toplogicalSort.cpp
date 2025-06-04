/*
   AOV网络定义:有向图所有的活动都表现在顶点，两个点之间的边视为先后顺序
   如果图中从V到W有一条有向路径，则V一定排在W之前，满足次条件的顶点序列成为一个拓扑序
   获得一个拓扑序的过程就是拓扑排序
   可以生成拓扑序则图中必定没有环路。
 */

#include "../graph/matrix_graph/MGraph.h"//对图进行拓扑排序
#include "../queue/linked_queue.hpp"//使用队列工具

//参数二  是顶点排序之后的序号
void toplogicalSort(MGraph graph, int TopNum[ ]){
     LinkedQueue<VertexType> queue;
     int Counter = 0;
     int v, w;

     int vertexNum = graph.getVertexNum();
     int *InDegree = new int[vertexNum * sizeof(int)];
     graph.getInDegree(InDegree);   /* 计算图G中各顶点的入度 */

     for( v = 1; v <= vertexNum; v++ )
          if( InDegree[v]==0 )
              queue.enqueue(v);
      while( ! queue.empty()) {
           v = queue.dequeue();
           TopNum[v] = ++Counter;      /* 赋顶点拓扑排序序号 */
           //获取v所有的邻接点
           int *VS = new int[vertexNum]{0};
           graph.getAllAdjVertex(v, VS);
           for(int j=0;j< vertexNum;j++){
                if(VS[j] && --InDegree[ j ] == 0 ){
                queue.enqueue(w);
              }
           }
           delete VS;
           VS = nullptr;
      }
      if( Counter != vertexNum )
           //Error( "出错,图存在环路" );

	  delete[] InDegree;
}