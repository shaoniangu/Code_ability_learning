#include <stdio.h>

#define ERROR -1


Vertex FindMinDist(MGraph, WeightType dist[])
{
    Vertex MinV, V;
    WeightType MinDist=INFINITY;
    for(V=0;V<Graph->Nv;V++)
    {
        if(dist[V]!=0 && dist[V]<MinDist)   //����δ����¼������dist��С��
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

    //��0Ϊ���ڵ��ʼ��dist��parent
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
    parent[0]=-1;   //0Ϊ��

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
            if(dist[W]!=0&&Graph->G[V][W]<INFINITY) //�Բ����������ϵ�V���ڽӵ�
            {
                if(Graph->G[V][W]<dist[W]) //��¼Vʹ��W���������ľ����С
                    dist[W]=Graph->G[V][W]; //����dist
                    parent[W]=V;        //��V���W�ĸ����
            }
        }

        if(VCount<Graph->Nv)
        {
            TotalWeight=ERROR;
        }
        return TotalWeight;
    }

}