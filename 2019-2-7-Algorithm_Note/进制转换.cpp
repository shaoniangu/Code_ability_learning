//进制转换提的思路：先转换成十进制数，再转化成其他进制数
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
    printf("%d进制数%d的十进制数为：%d\n", product, num, answer);
    return answer;
}

void TenConvertToOther(int num, int product)
{
    //除基取余法
    int z[40],index=0;
    do
    {
        z[index++]=num%product;
        num=num/product;
    }while(num!=0);

    printf("十进制数%d的%d进制数为：\n",num, product);
    for(int i=index-1;i>=0;i--)
    {
        printf("%d", z[i]);
    }
}

int main()
{
    int num,product1,product2;
    printf("请输入数和其进制以及目标进制，用空格隔开：");
    scanf("%d%d%d",&num,&product1,&product2);
    num=ConvertToTen(num,product1);
    TenConvertToOther(num,product2);
    return 0;
}