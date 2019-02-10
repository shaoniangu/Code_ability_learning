#include <stdio.h>

#define maxn 100

void merge(int A[], int L1, int R1, int L2, int R2)
{
    int i=L1, j=L2;
    int temp[maxn], index=0;
    while(i<=R1 && j<=R2)
    {
        if(A[i]<A[j])
        {
            temp[index++]=A[i++];
        }
        else
        {
            temp[index++]=A[j++];
        }
    }
    while(i<=R1) temp[index++]=A[i++];
    while(j<=R2) temp[index++]=A[j++];
    for(i=0;i<index;i++)
    {
        A[L1+i]=temp[i];
    }
}

void mergesort(int A[], int left, int right)
{
    if(left<right)
    {
        int mid =(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}


int main()
{
    int A[9]={5,1,6,3,2,4,0,8,7};
    mergesort(A,0,8);
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
    return 0;
}