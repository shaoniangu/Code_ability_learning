#include <stdio.h>
#include <math.h>

#define maxn 100010

bool isPrime(int n)
{
    if(n==1) return false;
    int sqr=(int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0) return false;
    }
}

void Find_Prime(int prime[], int * pNum)
{
    for(int i=1;i<maxn;i++)
    {
        if(isPrime(i))
        {
            prime[(*pNum)++]=i;
        }
    }
}

struct factor
{
    int x;
    int cnt;
}fac[10];

int main()
{
    int prime[maxn],pNum=0;
    Find_Prime(prime, &pNum);
    int n, num=0;
    printf("请输入待分解的数字：");
    scanf("%d", &n);
    if(n==1) printf("1=1");
    else
    {
        printf("%d=",n);
        int sqr=(int)sqrt(1.0*n);
        for(int i=0;i<pNum && prime[i]<=sqr;i++)
        {
            if(n%prime[i]==0)
            {
                fac[num].x=prime[i];
                fac[num].cnt=0;
                while(n%prime[i]==0)
                {
                    fac[num].cnt++;
                    n/=prime[i];
                }
                num++;
            }
            if(n==1) break;
        }

        if(n!=1)    //注意：如果没办法被根号n以内的质因子除尽，那么一定有一个大于根号n的质因子
        {
                fac[num].x=n;
                fac[num++].cnt=1;
        }

        for(int i=0;i<num;i++)
        {
            if(i>0) printf("*");
            printf("%d",fac[i].x);
            if(fac[i].cnt>1)
                printf("^%d", fac[i].cnt);
        }
    }
    return 0;
}