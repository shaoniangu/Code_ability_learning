//状态：d[i][j]为以i行j列为终点的自底而上地最大路径和
//状态转移方程：d[i][j]=max(d[i+1][j],d[i+1][j+1])+f[i][j], f[n][j]=f[n][j]
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=1000;

int f[maxn][maxn],dp[maxn][maxn];

int main()
{
    int n;
    printf("请输入数塔高度：");
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&f[i][j]);
    
    //DP 边界
    for(int j=1;j<=n;j++)
        dp[n][j]=f[n][j];

    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j], dp[i+1][j+1])+f[i][j];
        
    printf("Max = %d",dp[1][1]);
    return 0;
}