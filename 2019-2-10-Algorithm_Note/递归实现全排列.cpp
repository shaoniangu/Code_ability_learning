#include <cstdio>

void GenerateP(int P[], int n, int hashTable[], int index)
{
    //�ݹ�߽磬�Ѿ�������nλ��
    if(index==n)
    {
        printf("ȫ����Ϊ��");
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

    //�ݹ�ʽ��һ��һ������P��ÿһλ��������1��ʼ��ȫ���У�������2��ʼ��ȫ����......
    for(int i=0;i<n;i++)
    {
        if(hashTable[i]==false) //���i��û������
        {
            P[index]=i;
            hashTable[i]=true;
            GenerateP(P,n,hashTable,index+1);
            hashTable[i]=false; //������i��ͷ�������⣬��ԭ״̬
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