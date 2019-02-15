//状态：dp[i][v]，表示前i件物品签好装入容量为v的背包中所能获得的最大价值
//状态转移方程：不选第i件商品：dp[i][v]=dp[i-1][v]；和01背包问题的区别：选第i件商品：dp[i][v]=dp[i][v-w[i]]+c[i];
//为了节省空间，由于dp[i][v]之和dp[i-1]有关，不过和01背包问题不同，v的枚举要正序，因为第i轮需要当前轮和之前轮的左边的记过

#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=100;
const int maxv=1000;
int w[maxn], c[maxn], dp[maxv];

int main()
{
    int n, V;
    printf("请输入商品数量和背包体积：");
    scanf("%d%d",&n,&V);

    printf("请输入商品体积：");
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &w[i]);
    }

    printf("请输入商品价值：");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int v=w[i];v<V;v++)
        {
            dp[v]=max(dp[v], dp[v-w[i]]+c[i]);
            printf("%d ",dp[v]);
        }
        printf("\n");
    }

    int max=0;
    for(int v=0;v<=V;v++)
    {
        if(dp[v]>max)
        {
            max=dp[v];
        }
    }
    printf("%d", max);
    return 0;
}