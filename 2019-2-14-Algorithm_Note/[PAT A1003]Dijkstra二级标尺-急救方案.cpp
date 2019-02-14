#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,ed,G[MAXV][MAXV],weight[MAXV]; //n为顶点数，m为边数，s为起点
int d[MAXV],num[MAXV],w[MAXV];    //记录最短距离、最短距离个数、最大第二标尺weight
bool vis[MAXV]={false}; //记录是否已被访问

void Dijkstra(int s)
{
    fill(d,d+MAXV, INF);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));

    d[s]=0;
    w[s]=weight[s];
    num[s]=1;

    for(int i=0;i<n;i++)
    {
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false && d[j]<MIN)   //寻找未被访问的距离远点s最小的结点
            {
                u=j;
                MIN=d[j];
            }
        }

        if(u==-1) return; //剩余的点不连通

        vis[u]=true; //标记u已经被访问
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false && G[u][v]!=INF)  //更新纳入u而使得距离更近的u的未访问的邻接点
            {
                if(d[u]+G[u][v]<d[v])       //第一标尺
                {
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if (d[u]+G[u][v]==d[v])
                {
                    if(w[u]+weight[v]>w[v]) //第二标尺
                    {
                        w[v]=w[u]+weight[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
}


int main()
{
    int u,v;
    printf("请输入顶点个数、边数、起点、终点编号：");
    scanf("%d%d%d%d",&n,&m,&s,&ed);

    printf("请输入各点权:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &weight[i]);
    }

    fill(G[0],G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("请输入第%d组的两个顶点及其边权：", i+1);
        scanf("%d%d", &u,&v);
        scanf("%d", &G[u][v]);
        G[v][u]=G[u][v];
    }

    Dijkstra(s);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}