//其实这题最主要的是理解题目，n皇后问题要求n个皇后在n*n的格子中不在同一行、同一列、同一个对角线，其实就是实现一个n排列问题后，然后判断是
//是否有皇后在同一对角线上。
//那么其实也就是在之前递归实现全排列的代码的递归边界时候处理是否有皇后在同一对角线上。
#include <stdio.h>
#include <math.h>

void GenerateP(int P[], int n, int hashTable[], int index,int *count)
{
    //递归边界，已经处理了n位了
    if(index==n)
    {
        printf("全排列为：");
        for(int i=0;i<n;i++)
        {
            printf("%d", P[i]);
            printf("\t");
        }

        int flag=true;
        //判断是否有两个皇后在同一对角线上
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(i-j)==abs(P[i]-P[j]))
                    flag=false;
            }
        }
        if(flag)
        {
            (*count)++;
            printf("合法,已经寻得的合法个数为：%d\n",(*count));
        }
        else
        {
            printf("不合法\n");
        }
    }

    //递归式：一个一个填入P的每一位，先填入1开始的全排列，在填入2开始的全排列......
    for(int i=0;i<n;i++)
    {
        if(hashTable[i]==false) //如果i还没有填入
        {
            P[index]=i;
            hashTable[i]=true;
            GenerateP(P,n,hashTable,index+1,count);
            hashTable[i]=false; //处理完i开头的子问题，还原状态
        }
    }
}


int main()
{
    int n=5;
    int P[n];
    int hashTable[n]={false};
    int count=0;
    GenerateP(P,n,hashTable,0,&count);
    return 0;
}