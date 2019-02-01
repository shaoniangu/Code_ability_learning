#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 1000

typedef int ElementType;
typedef struct HNode * Heap;
struct HNode
{
    ElementType *Data;
    int Size;
    int Capacity;
};

typedef Heap MaxHeap;

MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H=(MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

bool IsFull(MaxHeap H)
{
    return (H->Size==H->Capacity);
}

bool IsEmpty(MaxHeap H)
{
    return (H->Size==0);
}

bool Insert(MaxHeap H, ElementType X)
{
    int i;
    if(IsFull(H))
    {
        printf("The maxheap is full!\n");
        return false;
    }
    i = ++(H->Size);
    for(;H->Data[i/2]<X;i/=2)
    {
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}

#define Error -1
ElementType DeleteMax(MaxHeap H)
{
    if(IsEmpty(H))
    {
        printf("The maxheap is empty!\n");
        return Error;
    }
    ElementType MaxItem;
    MaxItem=H->Data[1];
    ElementType X=H->Data[H->Size--];
    int Parent,Child;
    for(Parent=1;Parent*2<=H->Size;Parent=Child)
    {
        Child=Parent*2;
        if((Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]))
            ++Child;
        if(X>=H->Data[Child])
            break;
        else
        {
            H->Data[Parent]=H->Data[Child];
        }
    }
    H->Data[Parent]=X;
    return MaxItem;
}

void PercDown(MaxHeap H, int p)
{
    int Parent, Child;
    ElementType X;
    X = H->Data[p];
    for(Parent=p;Parent*2<=H->Size;Parent=Child)
    {
        Child=Parent*2;
        if((Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]))
            ++Child;
        if(X>=H->Data[Child])
            break;
        else
        {
            H->Data[Parent]=H->Data[Child];
        }
    }
    H->Data[Parent]=X;
}

void BuildHeap(MaxHeap H)
{
    int i;
    for(i=H->Size/2;i>0;i--)
        PercDown(H, i);
}

int main()
{
    MaxHeap H=CreateHeap(100);
    ElementType raw[11]={MAXDATA,2,9,4,3,6,7,4,1,8,5};
    H->Data=raw;
    H->Size=10;
    BuildHeap(H);
    Insert(H,10);
    ElementType res=DeleteMax(H);
    printf("%d\n",res);
    return 1;
}