#include <stdio.h>
#include <vector>

using namespace std;

vector<int> A;
vector<bool> visited;
int mindis=2e6, n;

void DFS(int index, int pos, int sumdis)
{
    if(index==n-1)
    {
        if(sumdis<mindis)
            mindis=sumdis;
        return;
    }
    int left=pos-1, right=pos+1;
    while(left>=0)
    {
        if(!visited[left])
            break;
        left--;
    }
    while(right<n)
    {
        if(!visited[right])
            break;
        right++;
    }
    if(left>=0 && right<n)
    {
        visited[left]=true;
        DFS(index+1, left, sumdis+A[pos]-A[left]);

        visited[left]=false;
        visited[right]=true;
        DFS(index+1, right,sumdis+A[right]-A[pos]);
    }
    else if(left<0)
    {
        visited[right]=true;
        DFS(index+1,right,sumdis+A[right]-A[pos]);
    }
    else
    {
        visited[left]=true;
        DFS(index+1, left, sumdis+A[pos]-A[left]);
    }
}


int main()
{
    int a,temp, i;
    scanf("%d%d", &n, &a);

    for(i=0;i<n;i++)
    {
        scanf("%d", &temp);
        A.push_back(temp);
        visited.push_back(false);
    }

    for(i=0;i<n;i++)
    {
        if(A[i]>a)
            break;
    }
    int pos,sumdis;
    if((A[i]-a)>(a-A[i-1]))
    {
        pos=i-1;
        visited[pos]=true;
        sumdis=a-A[i-1];
    }
    else
    {
        pos=i;
        visited[pos]=true;
        sumdis=A[i]-a;
    }
    DFS(1,pos,sumdis);
    printf("%d", mindis);
    return 0;
}