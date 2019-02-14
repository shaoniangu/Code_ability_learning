#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,ed, G[MAXV][MAXV], cost[MAXV][MAXV]; //n为顶点数，m为边数，s为起点
int d[MAXV], minCost=INF;    //记录最短距离
bool vis[MAXV]={false}; //记录是否已被访问
vector<int> pre[MAXV];
vector<int> tempPath, path;

void Dijkstra(int s)
{
    fill(d,d+MAXV, INF);
    d[s]=0;

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
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u]+G[u][v]==d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}


void DFS(int v)
{
    if(v==s)    //递归边界
    {
        tempPath.push_back(v);
        int tempCost=0;
        for(int i=tempPath.size()-1;i>0;i--)
        {
            int id=tempPath[i],idNext=tempPath[i-1];
            tempCost+=cost[id][idNext];
        }

        if(tempCost < minCost)
        {
            minCost=tempCost;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    int u,v;
    printf("请输入顶点个数、边数、起点和终点编号：");
    scanf("%d%d%d%d",&n,&m,&s,&ed);

    fill(G[0],G[0]+MAXV*MAXV, INF);
    fill(cost[0], cost[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("请输入第%d组的两个顶点及其边权和花费：", i+1);
        scanf("%d%d", &u,&v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]=G[u][v];
        cost[v][u]=cost[u][v];
    }

    Dijkstra(s);
    DFS(ed);

    for(int i=path.size()-1;i>=0;i--)
    {
        printf("%d ", path[i]);
    }

    printf("%d %d\n", d[ed], minCost);
    return 0;
}