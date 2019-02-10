#include <stdio.h>

int upper_bound(int A[],int left, int right, int x)
{
    int mid;
    while(left<right)   //ע��ѭ����������
    {
        mid=(left+right)/2;
        if(A[mid]<x)   //ע�������ж�����
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
    int A[5]={6,3,3,3,1};
    int left = upper_bound(A,0,5,3);
    printf("upper bound of 3 is %d\n",left);
    
    left = upper_bound(A,0,5,5);
    printf("upper bound of 5 is %d\n",left);

    left = upper_bound(A,0,5,6);
    printf("upper bound of 6 is %d\n",left);

    left = upper_bound(A,0,5,8);
    printf("upper bound of 8 is %d\n",left);

    return 0;
}