#include <cstdio>
#include <vector>

using namespace std;
const int maxn=100;
int n,k,x, maxSumSqu=-1, A[maxn];
vector<int> ans, temp;

void DFS(int index,int nowK, int sum, int sumSqu)
{
    if(nowK==k && sum==x)
    {
        if(sumSqu>maxSumSqu)
        {
            maxSumSqu=sumSqu;
            ans=temp;
        }
        return;
    }
    if(index==n || nowK>k || sum>x) return;

    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum+A[index], sumSqu+A[index]*A[index]);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);
}

int main()
{
    printf("�����������ܸ����ʹ�ѡ��ĸ�����");
    scanf("%d%d",&n,&k);
    printf("������͵Ĵ�С��");
    scanf("%d",&x);
    printf("����������֣�");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    DFS(0,0,0,0);
    printf("ѡ��%d�����Һ�Ϊ%d�����ƽ����Ϊ%d\n", n,x, maxSumSqu);
    printf("ѡ�����Ϊ��");
    for(int i=0;i<k;i++)
    {
        printf("%d\t", ans[i]);
    }
    return 0;
}