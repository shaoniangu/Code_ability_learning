//��ʵ��������Ҫ���������Ŀ��n�ʺ�����Ҫ��n���ʺ���n*n�ĸ����в���ͬһ�С�ͬһ�С�ͬһ���Խ��ߣ���ʵ����ʵ��һ��n���������Ȼ���ж���
//�Ƿ��лʺ���ͬһ�Խ����ϡ�
//��ô��ʵҲ������֮ǰ�ݹ�ʵ��ȫ���еĴ���ĵݹ�߽�ʱ�����Ƿ��лʺ���ͬһ�Խ����ϡ�
//��ʱ�������⴦��һ��λ�ú�����ʵ�Ѿ����Ϸ��ˣ�û�б�Ҫ�ٵݹ���ȥ�������������⣬����ֱ�ӷ�����һ��
#include <stdio.h>
#include <math.h>

void GenerateP(int P[], int n, int hashTable[], int index,int *count)
{
    //�ݹ�߽磬�Ѿ�������nλ�ˣ�������������һ���Ϸ�
    if(index==n)
    {
        printf("ȫ����Ϊ��");
        for(int i=0;i<n;i++)
        {
            printf("%d", P[i]);
            printf("\t");
        }

        (*count)++;
        printf("�Ϸ�,�Ѿ�Ѱ�õĺϷ�����Ϊ��%d\n",(*count));
    }

    //�ݹ�ʽ��һ��һ������P��ÿһλ��������1��ʼ��ȫ���У�������2��ʼ��ȫ����......
    for(int i=0;i<n;i++)
    {
        if(hashTable[i]==false) //���i��û������
        {
            int flag=true;      //�ж�Ŀǰ�����Ƿ�Ϸ�
            for(int pre=0;pre<index;pre++)
            {
                if(abs(index-pre)==abs(i-P[pre]))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                P[index]=i;
                hashTable[i]=true;
                GenerateP(P,n,hashTable,index+1,count);
                hashTable[i]=false; //������i��ͷ�������⣬��ԭ״̬
            }
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