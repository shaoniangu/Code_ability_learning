//˵����������������ӵĵ���

#include<stdio.h>
#include<string.h>

//�㷨�ʼǵĽⷨ
void InvertStr1()
{
    char str[100];
    printf("��������ӣ�");
    gets(str);
    int len=strlen(str);
    int r=0,h=0;
    char ans[100][100];
    for(int i=0;i<len;i++)
    {
        if(str[i]!=' ')
        {
            ans[r][h]=str[i];
            h++;
        }
        else
        {
            ans[r][h]='\0';
            r++;
            h=0;
        }
    }
    printf("���������������Ϊ��");
    for(int i=r;i>=0;i--)
    {
        printf("%s",ans[i]);
        if(i>0)
        {
            printf(" ");
        }
    }
}

//��scanf����
void InvertStr2()
{
    int num=0;
    char ans[100][100];
    printf("��������ӣ�");
    while(scanf("%s",ans[num])!=EOF)//ctrl+zΪֹͣ��־������ո���ᱻ����,��scanf�Կո�enter��tab������gets���Զ���ո�ֻ��enter����
    {
        printf("��������ӣ�");
        num++;
    }
    printf("���������������Ϊ��");
    for(int i=num-1;i>=0;i--)
    {
        printf("%s",ans[i]);
        if(i>0)
        {
            printf(" ");
        }
    }
}

int main()
{
    //InvertStr1(); //������ĩβ����ո�������һ���ո�ans�����һ�е����ǿ��ַ���
    InvertStr2();
    return 0;
}