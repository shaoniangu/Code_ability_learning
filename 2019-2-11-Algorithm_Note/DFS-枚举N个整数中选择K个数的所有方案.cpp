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
    printf("请输入数字总个数和待选择的个数：");
    scanf("%d%d",&n,&k);
    printf("请输入和的大小：");
    scanf("%d",&x);
    printf("请输入各数字：");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    DFS(0,0,0,0);
    printf("选择%d个数且和为%d的最大平方和为%d\n", n,x, maxSumSqu);
    printf("选择的数为：");
    for(int i=0;i<k;i++)
    {
        printf("%d\t", ans[i]);
    }
    return 0;
}