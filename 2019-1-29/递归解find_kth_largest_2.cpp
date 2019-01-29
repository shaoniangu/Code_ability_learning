# include <stdio.h>

void Swap(int *X, int *Y)
{
    int tmp;
    tmp = *X;
    *X=*Y;
    *Y=tmp;
}

int FindKthLargest(int S[], int K, int Left, int Right)
{
    int e=S[Left];
    int L=Left, R=Right;
    while(1)
    {
        while((Left<=Right) && (e<=S[Left])) Left++;
        while((Left<=Right) && (e>S[Right])) Right--;
        if (Left<Right)
            Swap(&S[Left], &S[Right]);
        else
            break;
    }
    Swap(&S[Left-1], &S[L]);
    if((Left-L-1)>=K)
        return FindKthLargest(S,K,L,Left-2);
    else if ((Left-L-1)<K-1)
        return FindKthLargest(S,K-(Left-L-1)-1,Left,R);
    else
    {
        return e;
    }
}


int main()
{
    int S[9] = {6,5,9,8,2,1,7,3,4};
    int e;
    e = FindKthLargest(S, 5, 0, 8);

    for (size_t i = 0; i < 9; i++)
    {
        printf("%d ", S[i]);
    }
    printf("\n%d", e);
    return 1;
}