//状态：d[i][j]表示A[i]和B[j]之前的最长公共子序列
//状态转移方程：如果A[i]==B[j], d[i][j]=d[i-1][j-1]+1;如果A[i]!=B[j],d[i][j]=max(d[i-1][j],d[i][j-1])

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=100;
char A[N],B[N];
int dp[N][N];

int main()
{
    int n;
    gets(A+1);
    gets(B+1);

    int lenA=strlen(A+1);
    int lenB=strlen(B+1);

    for(int i=0;i<=lenA;i++)
        dp[i][0]=0;
    for(int j=0;j<=lenB;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=lenA;i++)
    {
        for(int j=1;j<=lenB;j++)
        {
            if(A[i]==B[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[lenA][lenB]);
    return 0;
}