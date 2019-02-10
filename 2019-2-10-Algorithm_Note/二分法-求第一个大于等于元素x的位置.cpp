#include <stdio.h>

int lower_bound(int A[],int left, int right, int x)
{
    int mid;
    while(left<right)   //注意循环结束条件
    {
        mid=(left+right)/2;
        if(A[mid]>=x)   //注意条件判断条件
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
    int A[5]={1,3,3,3,6};
    int left = lower_bound(A,0,5,3);
    printf("lower bound of 3 is %d\n",left);
    
    left = lower_bound(A,0,5,5);
    printf("lower bound of 5 is %d\n",left);

    left = lower_bound(A,0,5,6);
    printf("lower bound of 6 is %d\n",left);

    left = lower_bound(A,0,5,8);
    printf("lower bound of 8 is %d\n",left);

    return 0;
}