#include <stdio.h>
#include <math.h>
#define PI 3.141592653

double f(double r, double h)
{
    double alpha=2*acos((r-h)/r);
    double L=2*sqrt(r*r-(r-h)*(r-h));
    double s1=alpha*r*r/2-L*(r-h)/2;
    double s2=PI*r*r/2;
    return s1/s2;
}

double approximate(double R, double r, double eps)
{
    double mid;
    double right=R, left=0;
    while(right-left>eps)   //注意循环结束条件
    {
        mid=(left+right)/2;
        if(f(R, mid)>r)   //注意条件判断条件
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
    return mid;
}

int main()
{
    double R=5, r=0.5;
    double eps=1e-5;
    double ans = approximate(R,r,eps);
    printf("The approximate root of f(h)=r is %f", ans);
}