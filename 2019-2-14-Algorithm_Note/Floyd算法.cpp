#include <cstdio>
#include <algorithm>

using namespace std;

const int INF=1e9;
const int MAXV=200;
int n,m;
int dis[MAXV][MAXV];

void Floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
}


int main()
{
    int u,v,w;
    printf("请输入顶点个数、边数：");
    scanf("%d%d",&n,&m);

    fill(dis[0],dis[0]+MAXV*MAXV, INF);

    for(int i=0;i<n;i++)
    {
        dis[i][i]=0;
    }

    for(int i=0;i<m;i++)
    {
        printf("请输入第%d组的两个顶点及其边权：", i+1);
        scanf("%d%d%d", &u,&v,&w);
        dis[u][v]=w;
    }

    Floyd();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}