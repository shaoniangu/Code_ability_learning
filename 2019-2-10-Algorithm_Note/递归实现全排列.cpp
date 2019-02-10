#include <cstdio>

void GenerateP(int P[], int n, int hashTable[], int index)
{
    //递归边界，已经处理了n位了
    if(index==n)
    {
        printf("全排列为：");
        for(int i=0;i<n;i++)
        {
            printf("%d", P[i]);
            if(i<n-1)
                printf("\t");
            else
            {
                printf("\n");
            }
        }
    }

    //递归式：一个一个填入P的每一位，先填入1开始的全排列，在填入2开始的全排列......
    for(int i=0;i<n;i++)
    {
        if(hashTable[i]==false) //如果i还没有填入
        {
            P[index]=i;
            hashTable[i]=true;
            GenerateP(P,n,hashTable,index+1);
            hashTable[i]=false; //处理完i开头的子问题，还原状态
        }
    }
}

int main()
{
    int n=3;
    int P[n];
    int hashTable[n]={false};
    GenerateP(P,n,hashTable,0);
    return 0;
}