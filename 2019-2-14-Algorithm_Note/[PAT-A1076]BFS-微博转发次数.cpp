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

vector<Node> Adj[MAXV]; //邻接表法表示图
bool inq[MAXV] = {false};   //记录结点是否已入队

int BFS(int s, int L)
{
    int numForward=0; //转发数
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
    printf("请输入节点数和层数上限：");
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
    {
        user.id=i;
        printf("请输入用户%d关注的人数:", i);
        scanf("%d",&numFollow);
        for(int j=0;j<numFollow;j++)
        {
            printf("请输入用户%d关注的第%d个用户的id:", i,j+1);
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }

    int numQuery,s;
    printf("请输入查询个数：");
    scanf("%d",&numQuery);
    for(int i=0;i<numQuery;i++)
    {
        memset(inq, false, sizeof(inq));
        printf("请输入第%d次查询的初始结点：",i+1);
        scanf("%d",&s);
        int numForward=BFS(s,L);
        printf("第%d次查询结果转发数为%d\n", i+1, numForward);
    }
    return 0;
}