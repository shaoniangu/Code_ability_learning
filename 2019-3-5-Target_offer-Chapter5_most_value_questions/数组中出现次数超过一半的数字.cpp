#include <cstdio>

int partition(int A[], int left, int right)
{
    int temp=A[left];
    while(left<right)
    {
        while(left<right && A[right]>temp)
        {
            right--;
        }
        A[left]=A[right];
        while(left<right && A[left]<=temp)
        {
            left++;
        }
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

void quickSort(int A[], int left, int right)
{
    if(left<right)
    {
        int pos=partition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}

int FindMoreThanHalf(int A[], int left, int right)
{
    if(A==NULL || left>=right)
        return -1;
    
    int middle=(right-left+1)>>1;
    int index=partition(A, left, right);
    while(index!=middle)
    {
        if(index>middle)
        {
            index=partition(A,left,index-1);
        }
        else
        {
            index=partition(A,index+1,right);
        }
    }
    int result=A[middle];
    return result;
}

int main()
{
    int A[10]={9,4,3,5,7,6,1,2,0,8};
    quickSort(A,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    int B[10]={9,1,3,1,7,1,1,2,1,1};
    int result=FindMoreThanHalf(B,0,9);
    printf("result is %d.\n", result);
    for(int i=0;i<10;i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}