#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,ed, G[MAXV][MAXV], cost[MAXV][MAXV]; //nΪ��������mΪ������sΪ���
int d[MAXV], minCost=INF;    //��¼��̾���
bool vis[MAXV]={false}; //��¼�Ƿ��ѱ�����
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
            if(vis[j]==false && d[j]<MIN)   //Ѱ��δ�����ʵľ���Զ��s��С�Ľ��
            {
                u=j;
                MIN=d[j];
            }
        }

        if(u==-1) return; //ʣ��ĵ㲻��ͨ

        vis[u]=true; //���u�Ѿ�������
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false && G[u][v]!=INF)  //��������u��ʹ�þ��������u��δ���ʵ��ڽӵ�
            {
                if(d[u]+G[u][v]<d[v])       //��һ���
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
    if(v==s)    //�ݹ�߽�
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
    printf("�����붥������������������յ��ţ�");
    scanf("%d%d%d%d",&n,&m,&s,&ed);

    fill(G[0],G[0]+MAXV*MAXV, INF);
    fill(cost[0], cost[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("�������%d����������㼰���Ȩ�ͻ��ѣ�", i+1);
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