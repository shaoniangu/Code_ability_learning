#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;

int main()
{
    int n;
    long long temp, x, y, ans=0;
    printf("请输入果堆数目：");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个果堆的重量：", i+1);
        scanf("%lld",&temp);
        q.push(temp);
    }

    while(q.size()>1)
    {
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        q.push(x+y);
        ans+=x+y;
    }
    printf("%lld", ans);
    return 0;
}