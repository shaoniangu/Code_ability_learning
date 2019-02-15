//状态：dp[i][j]表示以S[i]开始，以S[j]结束的子串是否是回文串
//状态转移方程： 如果S[i]==S[j], dp[i][j]=dp[i+1][j--];如果S[i]!=S[j],dp[i][j]=0;
#include <cstdio>
#include <cstring>

const int maxn=1000;
char S[maxn];
char dp[maxn][maxn];

int main()
{
    gets(S);
    int len=strlen(S), ans=1;
    memset(dp,0,sizeof(dp));

    for(int i=0;i<len;i++)
    {
        dp[i][i]=1;
        if(i<len-1)
        {
            if(S[i]==S[i+1])
            {
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }

    for(int L=3;L<=len;L++)
    {
        for(int i=0;i+L-1<len;i++)
        {
            int j=i+L-1;
            if(S[i]==S[j] && dp[i+1][j-1]==1)
            {
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}