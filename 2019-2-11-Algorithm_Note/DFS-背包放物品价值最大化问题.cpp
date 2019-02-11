#include <cstdio>

const int maxn=30;
int w[maxn], c[maxn];
int n,V, maxValue=0;


void DFS(int index, int sumW, int sumC)
{
    if(index==n)
    {
        if(sumW<=V && sumC>maxValue)
        {
            maxValue=sumC;
        }
        return;
    }

    DFS(index+1, sumW, sumC);       //DFS两个分支，一个是选，一个是不选，选就加上单价和重量
    DFS(index+1, sumW+w[index], sumC+c[index]);
}

void DFS2(int index, int sumW, int sumC)
{
    if(index==n)
    {
        return;
    }

    DFS(index+1, sumW, sumC);       //DFS两个分支，一个是选，一个是不选，选就加上单价和重量
    if(sumW+w[index]<=V)
    {
        if(sumC+c[index]>maxValue)
        {
            maxValue=sumC+c[index];
        }

        DFS(index+1, sumW+w[index], sumC+c[index]);
    }
}

int main()
{
    printf("请输入物品数量和体积：");
    scanf("%d%d",&n,&V);
    printf("请输入各物品重量：");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }

    printf("请输入各物品价格：");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    //DFS(0,0,0);
    //printf("1-不超过体积%d的最大价值为%d", V, maxValue);

    DFS2(0,0,0);
    printf("2-不超过体积%d的最大价值为%d", V, maxValue);
    return 0;
}