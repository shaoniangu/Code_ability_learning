#include <stdio.h>

int main()
{
    int n=6, A[n]={1,2,3,4,5,6};
    int i=0,j=n-1;
    int M=8;
    while(i<j)
    {
        if(A[i]+A[j]==M)
        {
            printf("%d+%d=%d\n", A[i], A[j], M);
            i++;
            j--;
        }
        else if (A[i]+A[j]>M)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}