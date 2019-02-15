//״̬��dp[i][v]����ʾǰi����Ʒǩ��װ������Ϊv�ı��������ܻ�õ�����ֵ
//״̬ת�Ʒ��̣���ѡ��i����Ʒ��dp[i][v]=dp[i-1][v]��ѡ��i����Ʒ��dp[i][v]=dp[i-1][v-w[i]]+c[i];
//Ϊ�˽�ʡ�ռ䣬����dp[i][v]֮��dp[i-1]�йأ�����v��ö��Ҫ������Ϊ��i����Ҫ��i-1�ֵ���ߵĽ��

#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=100;
const int maxv=1000;
int w[maxn], c[maxn], dp[maxv];

int main()
{
    int n, V;
    printf("��������Ʒ�����ͱ��������");
    scanf("%d%d",&n,&V);

    printf("��������Ʒ�����");
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &w[i]);
    }

    printf("��������Ʒ��ֵ��");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int v=V;v>=w[i];v--)
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