#include <cstdio>

bool isBST(int* sequence, int length)
{
    if(sequence==NULL || length<=0)
        return false;
    
    int root=sequence[length-1];
    int i=0;
    for(;i<length-1;i++)
    {
        if(sequence[i]>root)
            break;
    }
    int j=i;
    for(;j<length-1;j++)
    {
        if(sequence[j]<root)
            return false;
    }

    bool left=true;
    if(i>0)
        left=isBST(sequence, i);
    bool right=true;
    if(i<length-1)
        right=isBST(sequence+i, length-i-1);
    
    return(left&&right);
}


int main()
{
    int sequence[7]={5,7,6,9,11,10,8};
    bool res=isBST(sequence, 7);
    printf("%d", res);
    return 0;
}