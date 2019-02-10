#include <stdio.h>

int Partition(int A[], int left, int right)
{
    int temp=A[left];
    while(left<right)
    {
        while(left<right && A[right]>temp)
        {
            right--;
        }
        A[left]=A[right];
        while(left<right && A[left]<temp)
        {
            left++;
        }
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

void quicksort(int A[], int left, int right)
{
    if(left<right)
    {
        int pos=Partition(A,left,right);
        quicksort(A,left,pos-1);
        quicksort(A,pos+1,right);
    }
}


int main()
{
    int A[9]={5,1,6,3,2,4,0,8,7};
    quicksort(A,0,8);
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
    return 0;
}