#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,ed,G[MAXV][MAXV],weight[MAXV]; //nΪ��������mΪ������sΪ���
int d[MAXV],num[MAXV],w[MAXV];    //��¼��̾��롢��̾�����������ڶ����weight
bool vis[MAXV]={false}; //��¼�Ƿ��ѱ�����

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
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if (d[u]+G[u][v]==d[v])
                {
                    if(w[u]+weight[v]>w[v]) //�ڶ����
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
    printf("�����붥���������������㡢�յ��ţ�");
    scanf("%d%d%d%d",&n,&m,&s,&ed);

    printf("���������Ȩ:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &weight[i]);
    }

    fill(G[0],G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("�������%d����������㼰���Ȩ��", i+1);
        scanf("%d%d", &u,&v);
        scanf("%d", &G[u][v]);
        G[v][u]=G[u][v];
    }

    Dijkstra(s);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}