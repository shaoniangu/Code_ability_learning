#include <stdio.h>

double f(double x)
{
    return x*x;
}

double approximate(double left, double right, double x, double eps)
{
    double mid;
    while(right-left>eps)   //ע��ѭ����������
    {
        mid=(left+right)/2;
        if(f(mid)>x)   //ע�������ж�����
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
    double left = 1, right=2;
    double x =2,eps=1e-5;
    double ans = approximate(left,right,x,eps);
    printf("The approximate value of sqrt(%f) is %f", x, ans);
}