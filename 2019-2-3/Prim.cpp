#include <stdio.h>

#define ERROR -1


Vertex FindMinDist(MGraph, WeightType dist[])
{
    Vertex MinV, V;
    WeightType MinDist=INFINITY;
    for(V=0;V<Graph->Nv;V++)
    {
        if(dist[V]!=0 && dist[V]<MinDist)   //返回未被收录顶点中dist最小者
        {
            MinDist=dist[V];
            MinV=V;
        }
    }
    if(MinDist<INFINITY)
    {
        return MinV;
    }
    else
    {
        return ERROR;
    }
}

int Prim(MGraph Graph, LGraph MST)
{
    WeightType dist[MaxVertexNum],TotalWeight;
    Vertex parent[MaxVertexNum],V,W;
    int VCount;
    Edge E;

    //以0为根节点初始化dist和parent
    for(V=0;V<Graph->Nv;V++)
    {
        dist[V]=Graph->G[0][V];
        parent[V]=0;
    }

    TotalWeight=0;
    VCount=0;
    MST=CreateGraph(Graph->Nv);
    E=(Edge)malloc(sizeof(struct ENode));

    dist[0]=0;
    VCount++;
    parent[0]=-1;   //0为根

    while(1)
    {
        V=FindMinDist(Graph,dist);
        if(V==ERROR)
        {
            break;
        }
        E->V1=parent[V];
        E->V2=V;
        E->Weight=dist[V];
        InsertEdge(MST,E);
        TotalWeight+=dist[V];
        dist[V]=0;
        VCount++;

        for(W=0;W<Graph->Nv;W++)
        {
            if(dist[W]!=0&&Graph->G[V][W]<INFINITY) //对不在生成树上的V的邻接点
            {
                if(Graph->G[V][W]<dist[W]) //收录V使得W到生成树的距离减小
                    dist[W]=Graph->G[V][W]; //更新dist
                    parent[W]=V;        //把V设成W的父结点
            }
        }

        if(VCount<Graph->Nv)
        {
            TotalWeight=ERROR;
        }
        return TotalWeight;
    }

}