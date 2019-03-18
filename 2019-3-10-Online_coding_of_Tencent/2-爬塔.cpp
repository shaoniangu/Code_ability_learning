#include <stdio.h>

int A[10000], n, mintime=65535;

void DFS(int index, int sumtime, bool magic_flag)
{
    if(index >= n)
    {
        if(sumtime<mintime)
            mintime=sumtime;
        return;
    }
    
    if(magic_flag)
    {
        DFS(index+1, sumtime, false);
        DFS(index+2, sumtime, false);
        DFS(index+1, sumtime+A[index], true);
    }
    else
    {
        DFS(index+1, sumtime+A[index], true);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
    }
    DFS(0, 0, true);
    printf("%d", mintime);
    return 0;
}