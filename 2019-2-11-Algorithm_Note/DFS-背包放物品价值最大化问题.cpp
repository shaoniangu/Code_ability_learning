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

    DFS(index+1, sumW, sumC);       //DFS������֧��һ����ѡ��һ���ǲ�ѡ��ѡ�ͼ��ϵ��ۺ�����
    DFS(index+1, sumW+w[index], sumC+c[index]);
}

void DFS2(int index, int sumW, int sumC)
{
    if(index==n)
    {
        return;
    }

    DFS(index+1, sumW, sumC);       //DFS������֧��һ����ѡ��һ���ǲ�ѡ��ѡ�ͼ��ϵ��ۺ�����
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
    printf("��������Ʒ�����������");
    scanf("%d%d",&n,&V);
    printf("���������Ʒ������");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }

    printf("���������Ʒ�۸�");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    //DFS(0,0,0);
    //printf("1-���������%d������ֵΪ%d", V, maxValue);

    DFS2(0,0,0);
    printf("2-���������%d������ֵΪ%d", V, maxValue);
    return 0;
}