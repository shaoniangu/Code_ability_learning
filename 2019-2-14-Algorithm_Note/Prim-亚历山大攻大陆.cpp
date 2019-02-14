#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV=1000;
const int INF=1e9;

int n,m,s,G[MAXV][MAXV]; //nΪ��������mΪ������sΪ���
int d[MAXV];    //��¼��̾���
bool vis[MAXV]={false}; //��¼�Ƿ��ѱ�����

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
            if(vis[j]==false && d[j]<MIN)   //Ѱ��δ�����ʵľ���Զ��s��С�Ľ��
            {
                u=j;
                MIN=d[j];
            }
        }

        if(u==-1) return -1; //ʣ��ĵ㲻��ͨ

        vis[u]=true; //���u�Ѿ�������
        ans+=d[u];
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false && G[u][v]!=INF && G[u][v]<d[v])  //��������u��ʹ�þ��������u��δ���ʵ��ڽӵ�
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
    printf("�����붥�������������");
    scanf("%d%d",&n,&m);

    fill(G[0],G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++)
    {
        printf("�������%d����������㼰���Ȩ��", i+1);
        scanf("%d%d%d", &u,&v,&w);
        G[u][v]=G[v][u]=w;
    }

    int ans = Prim();
    printf("%d", ans);
    return 0;
}