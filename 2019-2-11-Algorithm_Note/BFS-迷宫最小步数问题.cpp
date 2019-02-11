#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=100;

struct node
{
    int x,y;
    int step; //记录层数，用以表征经历了几步
}S,T,Node;

int n,m;
char maze[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};


bool judge(int x, int y)
{
    if(x>=n || x<0 || y>=m || y<0) return false;
    if(maze[x][y]=='*'|| inq[x][y]==true) return false;
    return true;
}

int BFS()
{
    queue<node> Q;
    Q.push(S);
    inq[S.x][S.y]=true;

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        if(top.x==T.x && top.y==T.y)    return top.step;

        for(int i=0;i<4;i++)
        {
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            if(judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                Node.step=top.step+1;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;
}

int main()
{
    n=5;
    m=5;
    char temp[n][m] = {{'.','.','.','.','.'},{'.','*','.','*','.'},{'.','*','S','*','.'},{'.','*','*','*','.'},{'.','.','.','T','*'}};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            maze[i][j] = temp[i][j];

    S.x=2;
    S.y=2;
    T.x=4;
    T.y=3;
    S.step=0;
    printf("%d", BFS());
    return 0;
}