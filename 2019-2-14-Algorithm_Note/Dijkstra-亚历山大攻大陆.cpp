#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,G[MAXV][MAXV]; //nΪ��������mΪ������sΪ���
int d[MAXV];    //��¼��̾���
bool vis[MAXV]={false}; //��¼�Ƿ��ѱ�����

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
            if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v])  //��������u��ʹ�þ��������u��δ���ʵ��ڽӵ�
            {
                d[v]=d[u]+G[u][v];
            }
        }
    }
}


int main()
{
    int u,v,w;
    printf("�����붥�����������������ţ�");
    scanf("%d%d%d",&n,&m,&s);

    fill(G[0],G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("�������%d����������㼰���Ȩ��", i+1);
        scanf("%d%d%d", &u,&v,&w);
        G[u][v]=w;
    }

    Dijkstra(s);
    for(int i=0;i<n;i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}