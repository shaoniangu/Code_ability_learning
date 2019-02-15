//״̬��dp[i]��ʾ�Ե�i��Ԫ��A[i]��β���������
//״̬ת�Ʒ��̣���A[j]�ӵ�dp[i]����������к��Ƿ����㲻�½�(��A[j]>=A[i]),dp[i]=max{i,dp[j]+1}

#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100;
int A[N], dp[N];

int main()
{
    int n;
    printf("���������г��ȣ�");
    scanf("%d",&n);

    printf("���������У�");
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