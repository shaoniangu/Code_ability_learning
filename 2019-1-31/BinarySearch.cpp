#include <stdio.h>
#include <stdlib.h>

#define NotFound -1

typedef struct List * PtrToList;
typedef int ElementType;
typedef int Position;
struct List
{
    ElementType *Data;
    Position Last;
};
typedef struct List* PList;

Position BinarySearch(PList Tb, ElementType K)
{
    Position left,right,mid;
    left=0;
    right=Tb->Last;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(K<Tb->Data[mid])
        {
            right=mid-1;
        }
        else if (K>Tb->Data[mid])
        {
            left=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return NotFound;
}

int main()
{
    Position Last=9;
    PList Tb=(PList)malloc(sizeof(struct List));
    Tb->Data = (ElementType *)malloc((Last+1)*sizeof(ElementType));
    Tb->Last = Last;
    ElementType Data[10]= {0,1,2,3,4,5,6,7,8,9};
    Tb->Data = Data;
    Position result = BinarySearch(Tb,2);
    printf("The index of %d is %d", 2, result);
    return 1;
}