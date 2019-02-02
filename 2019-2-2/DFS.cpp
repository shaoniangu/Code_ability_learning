#include <stdio.h>
#include "图-邻接表.cpp"

bool Visited[MaxVertexNum]={false};

void Visit(Vertex V)
{
    printf("正在访问顶点%d.\n", V);
}

void DFS(LGraph Graph, Vertex V, void(*Visit)(Vertex))
{
    PtrToAdjVNode W;
    Visit(V);
    Visited[V]=true;

    for(W=Graph->G[V].FirstEdge;W;W=W->Next)
    {
        if(!Visited[W->AdjV])
            DFS(Graph, W->AdjV,Visit);
    }    
}

int main()
{
    LGraph Graph=BuildGraph();
    PrintLGraph(Graph);
    DFS(Graph,0,Visit);
    return 1;
}