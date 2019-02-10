// 木棒切割问题也即求第一个k<K的切割长度L，也即求第一个生成木棒数量k小于设定数量K，然后减一。
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
    while(left<right)   //注意循环结束条件
    {
        mid=(left+right)/2;
        if(f(A, n, mid)<K)   //注意条件判断条件
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