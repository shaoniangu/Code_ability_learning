//״̬��d[i]Ϊ��i������A[i]Ϊ�յ��������������к�
//״̬ת�Ʒ��̣�d[i]=max(A[i], d[i-1]+A[i])

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=10000;
int A[maxn], dp[maxn];

int main()
{
    int n;
    printf("���������г��ȣ�");
    scanf("%d",&n);

    printf("���������У�");
    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);

    dp[0]=A[0];
    for(int i=1;i<n;i++)
        dp[i]=max(A[i], dp[i-1]+A[i]);
    
    int k=0;
    for(int i=1;i<n;i++)
        if(dp[i]>dp[k])
            k=i;
    printf("Max = %d", dp[k]);
    return 0;
}