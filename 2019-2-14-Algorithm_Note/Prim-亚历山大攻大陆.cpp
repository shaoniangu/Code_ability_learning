#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,G[MAXV][MAXV]; //n为顶点数，m为边数，s为起点
int d[MAXV];    //记录最短距离
bool vis[MAXV]={false}; //记录是否已被访问

int Prim()
{
    fill(d,d+MAXV, INF);
    d[0]=0;
    int ans=0;

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

        if(u==-1) return -1; //剩余的点不连通

        vis[u]=true; //标记u已经被访问
        ans+=d[u];
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false && G[u][v]!=INF && G[u][v]<d[v])  //更新纳入u而使得距离更近的u的未访问的邻接点
            {
                d[v]=G[u][v];
            }
        }
    }
    return ans;
}


int main()
{
    int u,v,w;
    printf("请输入顶点个数、边数：");
    scanf("%d%d",&n,&m);

    fill(G[0],G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("请输入第%d组的两个顶点及其边权：", i+1);
        scanf("%d%d%d", &u,&v,&w);
        G[u][v]=G[v][u]=w;
    }

    int ans = Prim();
    printf("%d", ans);
    return 0;
}