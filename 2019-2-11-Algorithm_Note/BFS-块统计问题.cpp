#include <cstdio>
#include <queue>

using namespace std;

struct node
{
    int x,y;
}Node;

const int maxn=100;
int n,m;
int matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};


bool judge(int x, int y)
{
    if(x>=n || x<0 || y>=m || y<0) return false;
    if(matrix[x][y]==0|| inq[x][y]==true) return false;
    return true;
}

void BFS(int x, int y)
{
    queue<node> Q;
    Node.x=x, Node.y=y;
    Q.push(Node);
    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            if(judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main()
{
    n=6;
    m=7;
    int temp[n][m] = {{0,1,1,1,0,0,1},{0,0,1,0,0,0,0},{0,0,0,0,1,0,0},{0,0,0,1,1,1,0},{1,1,1,0,1,0,0},{1,1,1,1,0,0,0}};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        matrix[i][j] = temp[i][j];

    int ans=0;
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<m;y++)
        {
            if(matrix[x][y]==1 && inq[x][y]==false)
            {
                ans++;
                BFS(x,y);
            }
        }
    }
    printf("%d", ans);
    return 0;
}