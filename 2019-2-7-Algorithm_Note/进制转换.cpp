//����ת�����˼·����ת����ʮ����������ת��������������
#include<stdio.h>
int ConvertToTen(int num, int product)
{
    int answer=0,p=1,y=num;
    while(y!=0)
    {
        answer+=(y%10)*p;
        y=y/10;
        p=p*product;
    }
    printf("%d������%d��ʮ������Ϊ��%d\n", product, num, answer);
    return answer;
}

void TenConvertToOther(int num, int product)
{
    //����ȡ�෨
    int z[40],index=0;
    do
    {
        z[index++]=num%product;
        num=num/product;
    }while(num!=0);

    printf("ʮ������%d��%d������Ϊ��\n",num, product);
    for(int i=index-1;i>=0;i--)
    {
        printf("%d", z[i]);
    }
}

int main()
{
    int num,product1,product2;
    printf("����������������Լ�Ŀ����ƣ��ÿո������");
    scanf("%d%d%d",&num,&product1,&product2);
    num=ConvertToTen(num,product1);
    TenConvertToOther(num,product2);
    return 0;
}