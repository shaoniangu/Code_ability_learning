#include <stdio.h>
#define MaxVertexNum 1000

bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
    Vertex i,j,k;

    for(i=0;i<Graph->Nv;i++)
        for(j=0;j<Graph->Nv;j++)
        {
            D[i][j]=Graph->G[i][j];
            path[i][j]=-1;
        }

    for(k=0;k<Graph->Nv;k++)
    {
        for(i=0;i<Graph->Nv;i++)
        {
            for(j=0;j<Graph->Nv;j++)
            {
                if(D[i][k]+D[k][j]<D[i][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    if(i==j && D[i][j]<0)
                        return false;
                    path[i][j]=k;
                }
            }
        }
    }
    return true;
}