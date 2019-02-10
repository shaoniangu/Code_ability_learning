// ľ���и�����Ҳ�����һ��k<K���и��L��Ҳ�����һ������ľ������kС���趨����K��Ȼ���һ��
#include <stdio.h>

int f(int A[], int n, int L)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        k+=A[i]/L;
    }
    return k;
}


int upper_bound(int A[],int n, int K,int left, int right)
{
    int mid;
    while(left<right)   //ע��ѭ����������
    {
        mid=(left+right)/2;
        if(f(A, n, mid)<K)   //ע�������ж�����
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

int main()
{
    int A[3]={10,24,15},n=3;
    int left = upper_bound(A,n,7,1,10);
    printf("%d\n",left-1);
    return 0;
}