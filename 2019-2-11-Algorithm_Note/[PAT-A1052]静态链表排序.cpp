#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100005;

struct Node{
    int address, data, next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b)
{
    if(a.flag==false || b.flag==false)
    {
        return a.flag>b.flag;       // 先按结点有无效排序，无效结点放到后面去
    }
    else
    {
        return a.data<b.data;       //按data从小到大排序
    }
}

int main()
{
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;
    }

    int n,begin,address;
    printf("请输入结点个数和起始结点地址：");
    scanf("%d%d",&n,&begin);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个结点的地址：",i+1);
        scanf("%d",&address);

        printf("请输入第%d个结点的数据和指向的节点地址：",i+1);
        scanf("%d%d",&node[address].data, &node[address].next);
        node[address].address=address;
    }

    int count=0,p=begin;
    while(p!=-1)
    {
        node[p].flag=true;
        count++;
        p=node[p].next;
    }

    if(count==0)
    {
        printf("0 -1");
    }
    else
    {
        sort(node,node+maxn,cmp);
    }

    printf("%d %05d\n",count, node[0].address);
    for(int i=0;i<count;i++)
    {
        if(i!=count-1)
        {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
        }
        else
        {
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}