#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x*x - 2*x;
}

double approximate(double left, double right, double eps)
{
    double mid;
    while(abs(f(mid))>eps)   //ע��ѭ����������
    {
        mid=(left+right)/2;
        if(f(mid)>0)   //ע�������ж�����
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
    double left = 1, right=3;
    double eps=1e-5;
    double ans = approximate(left,right,eps);
    printf("The approximate root in [%f,%f] of f is %f", left,right, ans);
}