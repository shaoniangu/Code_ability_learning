//状态：dp[i]表示以第i个元素A[i]结尾的最长子序列
//状态转移方程：将A[j]加到dp[i]代表的子序列后是否满足不下降(即A[j]>=A[i]),dp[i]=max{i,dp[j]+1}

#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100;
int A[N], dp[N];

int main()
{
    int n;
    printf("请输入序列长度：");
    scanf("%d",&n);

    printf("请输入序列：");
    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);

    int ans=-1;
    for(int i=0;i<n;i++)
    {    
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if((A[i]>=A[j]) && (dp[j]+1>dp[i]))
                dp[i]=dp[j]+1;
        }
        ans=max(ans, dp[i]);
    }
    printf("MAX = %d", ans);
    return 0;
}