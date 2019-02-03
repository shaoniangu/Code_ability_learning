#include <stdio.h>
#define ERROR -1
#define MaxVertexNum 1000

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
    Vertex MinV,V;
    int MinDist = INFINITY;

    for(V=0;V<Graph->Nv;V++)
    {
        if(collected[V]==false && dist[V]<MinDist)
        {
            MinDist=dist[V];
            MinV= V;
        }
    }

    if (MinDist<INFINITY)
        return MinV;
    else
    {
        return ERROR;
    }
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
    int collected[MaxVertexNum];
    Vertex V,W;

    // ��ʼ��
    for(V=0;V<Graph->Nv;V++)
    {
        dist[V]=Graph->G[S][V];
        if(dist[V]<INFINITY)
        {
            path[V]=S;
        }
        else
        {
            path[V]=-1;
        }
        collected[V]=false;
    }

    dist[S]=0;
    collected[S]=true;

    while(1)
    {
        V=FindMinDist(Graph, dist, collected);
        if(V==ERROR)
        {
            break;
        }
        collected[V]=true;
        for(W=0;W<Graph->Nv;W++)
        {
            if(collected[W]==false && Graph->G[V][W]<IFINITY)   //��û�б���¼��V���ڽӵ�
            {
                if(Graph->G[V][W]<0)
                {
                    return false;
                }
                if(dist[V]+Graph->G[V][W]<dist[W])
                {
                    dist[W]=dist[V]+Graph->G[V][W]; //�����¼Vʹ��S��W�ľ����С������dist[W]��������S��W��·��
                    path[W]=V;
                }
            }
        }
    }
    return true;
}

