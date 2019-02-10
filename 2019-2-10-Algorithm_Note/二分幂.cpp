#include <stdio.h>
typedef int LL;

LL binaryPow(LL a, LL b, LL m)
{
    if(b==0) return 1;
    if(b%2==1) return a * binaryPow(a, b-1,m) % m;
    else
    {
        LL mul=binaryPow(a,b/2,m);
        return mul*mul % m;
    }
}

LL binaryPow2(LL a, LL b, LL m)
{
    LL ans =1;
    while(b>0)
    {
        if(b&1)
        {
            ans=ans*a % m;
        }
        a=a*a%m;
        b>>=1;
    }
    return ans;
}

int main()
{
    LL a=2, b=10, m=3;
    LL ans = binaryPow(a,b,m);
    printf("%d\n", ans);
    LL ans2 = binaryPow2(a,b,m);
    printf("%d\n", ans2);
    return 0;
}