#include <stdio.h>

bool TopSort(LGraph Graph, Vertex TopOrder[])
{
    int Indegree[MaxVertexNum],cnt;
    Vertex V;
    PtrToAdjNode W;
    Queue Q=CreateQueue(Graph->Nv);

    //初始化每个节点的入度
    for(V=0;V<Graph->Nv;V++)
        Indegree[V]=0;
    
    for(V=0;V<Graph->Nv;V++)
        for(W=Graph->G[V].FirstEdge;W;W=W->Next)
            Indegree[W->AdjV]++;

    for(V=0;V<Graph->Nv;V++)
        if(Indegree[V])
        {
            AddQ(Q,V);
        }
    
    cnt=0;
    while(!IsEmpty(Q))
    {
        V=Delete(Q);
        TopOrder[cnt++]=V;

        for(W=Graph->G[V].FirstEdge;W;W=W->Next)
        {
            if(--Indegree[W->AdjV]==0)
            {
                AddQ(Q,W->Adjv);
            }
        }
    }

    if(cnt!=Graph->Nv)
    {
        return false;
    }
    else
    {
        return true;
    }
}