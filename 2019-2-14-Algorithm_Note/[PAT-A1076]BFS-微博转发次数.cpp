#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int MAXV=1000;

struct Node
{
    int id;
    int layer;
};

vector<Node> Adj[MAXV]; //�ڽӱ���ʾͼ
bool inq[MAXV] = {false};   //��¼����Ƿ������

int BFS(int s, int L)
{
    int numForward=0; //ת����
    queue<Node> q;
    Node start;
    start.id=s;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;

    while(!q.empty())
    {
        Node topNode=q.front();
        q.pop();
        int u=topNode.id;
        for(int i=0;i<Adj[u].size();i++)
        {
            Node next=Adj[u][i];
            next.layer=topNode.layer+1;
            if(inq[next.id]==false && next.layer<=L)
            {
                q.push(next);
                inq[next.id]=true;
                numForward++;
            }
        }
    }
    return numForward;
}


int main()
{
    Node user;
    int n,L,numFollow,idFollow;
    printf("������ڵ����Ͳ������ޣ�");
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
    {
        user.id=i;
        printf("�������û�%d��ע������:", i);
        scanf("%d",&numFollow);
        for(int j=0;j<numFollow;j++)
        {
            printf("�������û�%d��ע�ĵ�%d���û���id:", i,j+1);
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }

    int numQuery,s;
    printf("�������ѯ������");
    scanf("%d",&numQuery);
    for(int i=0;i<numQuery;i++)
    {
        memset(inq, false, sizeof(inq));
        printf("�������%d�β�ѯ�ĳ�ʼ��㣺",i+1);
        scanf("%d",&s);
        int numForward=BFS(s,L);
        printf("��%d�β�ѯ���ת����Ϊ%d\n", i+1, numForward);
    }
    return 0;
}