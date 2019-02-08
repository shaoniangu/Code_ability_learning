#include <cstdio>
#include <string.h>

int hashFunc(char s[], int len)
{
    int id=0;
    for(int i=0;i<len;i++)
    {
        id=id*26+(s[i]-'A');
    }
    return id;
}

int main()
{
    int maxn=100;
    int n,m;
    char S[maxn][4], temp[4];
    int hashtable[26*26*26];
    printf("请输入n，m：");
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个字符串：",i+1);
        scanf("%s",S[i]);
        int id=hashFunc(S[i],3);
        hashtable[id]++;
    }

    for(int i=0;i<m;i++)
    {
        printf("请输入第%d个待查字符串：",i+1);
        scanf("%s",temp);
        int id=hashFunc(temp,3);
        printf("出现过%d次。\n",hashtable[id]);
    }

    return 0;
}