#include <stdio.h>

typedef int ElementType;
# define N 100 

ElementType FindKthLargest(ElementType S[], int num_s, int K)
{
    ElementType S1[N],S2[N];
    int num1=0, num2=0;
    ElementType e = S[0];
    for (int i = 1; i < num_s; i++)
    {
        if (e>S[i])
        {
            S1[num1] = S[i];
            num1++;
        }
        else
        {
            S2[num2] = S[i];
            num2++;
        }
    }
    if (num1 >= K)
    {
        return FindKthLargest(S1, num1, K);
    }
    else if (num1 < K-1)
    {
        return FindKthLargest(S2, num2, K-num1-1);
    }
    else
    {
        return e;
    }
}


int main()
{
    ElementType S[9] = {6,5,9,8,2,1,7,3,4};
    ElementType num_s = 9;
    int answer;
    answer = FindKthLargest(S, num_s, 5);
    printf("%d", answer);
    return 1;
}