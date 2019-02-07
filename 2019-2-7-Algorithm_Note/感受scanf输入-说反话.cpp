//说反话：反向输出句子的单词

#include<stdio.h>
#include<string.h>

//算法笔记的解法
void InvertStr1()
{
    char str[100];
    printf("请输入句子：");
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
    printf("反向输出单词序列为：");
    for(int i=r;i>=0;i--)
    {
        printf("%s",ans[i]);
        if(i>0)
        {
            printf(" ");
        }
    }
}

//用scanf输入
void InvertStr2()
{
    int num=0;
    char ans[100][100];
    printf("请输入句子：");
    while(scanf("%s",ans[num])!=EOF)//ctrl+z为停止标志，多个空格均会被舍弃,且scanf以空格，enter和tab结束，gets可以读入空格，只以enter结束
    {
        printf("请输入句子：");
        num++;
    }
    printf("反向输出单词序列为：");
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
    //InvertStr1(); //如果最后末尾输入空格，输出会多一个空格，ans的最后一行单词是空字符串
    InvertStr2();
    return 0;
}