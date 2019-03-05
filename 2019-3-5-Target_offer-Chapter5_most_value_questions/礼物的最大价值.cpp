#include <cstdio>
int max(int a, int b)
{
    return a>b?a:b;
}

int getMaxValue(int A[][4], int rows, int cols)
{
    if(A==NULL || rows<=0 || cols<=0)
        return 0;
    
    int maxvalue[rows][cols]={0};
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int left=0;
            int up=0;
            if(i>0)
            {
                up=maxvalue[i-1][j];
            }
            if(j>0)
            {
                left=maxvalue[i][j-1];
            }
            maxvalue[i][j]=max(left, up) + A[i][j];
        }
    }
    return maxvalue[rows-1][cols-1];
}


int main()
{
    int array[4][4]={{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
    printf("maxvalue=%d", getMaxValue(array,4,4));
    return 0;
}