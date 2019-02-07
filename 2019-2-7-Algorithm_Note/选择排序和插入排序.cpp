#include<stdio.h>

void SelectSort(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        int k=i;
        for(int j=i;j<n;j++)
        {
            if (A[j]<A[k])
            {
                k=j;
            }
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
}

void InsertSort(int A[], int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=A[i],j=i;
        while(j>0 && temp<A[j-1])
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}

int main()
{
    int A[10]={3,6,4,2,9,1,0,4,7,6};
    //SelectSort(A,10);
    InsertSort(A,10);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d",A[i]);
        if(i<9)
            printf(" ");
    }
    return 0;
}