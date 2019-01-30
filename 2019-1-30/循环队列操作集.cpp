#include <stdio.h>
#include <stdlib.h>
#define Error -1e9

typedef struct QNode *PtrToQNode;
typedef int Position;
typedef int ElementType;
struct QNode
{
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;


Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front = Q->Rear =0;
    Q->MaxSize=MaxSize;   
    return Q;
}

bool isFull(Queue Q)
{
    return ((Q->Rear + 1)%Q->MaxSize==Q->Front);
}

bool isEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}

bool AddQ(Queue Q, ElementType x)
{
    if(isFull(Q))
    {
        printf("The queue is full!\n");
        return false;
    }
    else
    {
        Q->Rear = (Q->Rear + 1)% Q->MaxSize;
        Q->Data[Q->Rear]=x;
        return true;
    }
}

ElementType DeleteQ(Queue Q)
{
    if(isEmpty(Q))
    {
        printf("The queue is empty!\n");
        return Error;
    }
    else
    {
        Q->Front=(Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];
    }
}

void PrintQ(Queue Q)
{
    Position front=Q->Front;
    Position rear = Q->Rear;
    while(front!=rear)
    {
        front = (front+1)%Q->MaxSize;
        printf("%d ",Q->Data[front]);
    }
    printf("\n");
}

typedef struct Node * PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Pos;

typedef struct ChainQNode * PtrToChainQNode;
struct ChainQNode 
{
    Pos Front,Rear;
};
typedef PtrToChainQNode ChainQueue;

bool isChainQEmpty(ChainQueue Q)
{
    return (Q->Front==NULL);
}

ChainQueue CreateChainQueue()
{
    ChainQueue Q = (ChainQueue)malloc(sizeof(struct ChainQNode));
    Q->Front = Q->Rear=NULL;
    return Q;
}

bool AddChainQ(ChainQueue Q, ElementType x)
{
    Pos Cell = (Pos)malloc(sizeof(struct Node));
    Cell->Data=x;
    Cell->Next=NULL;
    if(Q->Front==NULL)
    {
        Q->Rear=Q->Front=Cell;
    }
    else
    {
        Q->Rear->Next=Cell;
        Q->Rear=Cell;   
    }
    return true;
}

ElementType DeleteChainQ(ChainQueue Q)
{
    Pos FrontCell;
    ElementType FrontElem;

    if(isChainQEmpty(Q))
    {
        printf("The chain queue is empty!\n");
        return Error;
    }
    else
    {
        FrontCell=Q->Front;
        if(Q->Front == Q->Rear)
        {
            Q->Front=Q->Rear=NULL;
        }
        else
        {
            Q->Front = Q->Front->Next;
        }
        FrontElem=FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }
}

void PrintChainQ(ChainQueue Q)
{
    Pos front = Q->Front;
    while(front!=NULL)
    {
        printf("%d ", front->Data);
        front=front->Next;
    }
    printf("\n");
}

int main()
{
    Queue Q=CreateQueue(10);
    AddQ(Q,1);
    AddQ(Q,2);
    AddQ(Q,3);
    PrintQ(Q);
    DeleteQ(Q);
    PrintQ(Q);

    ChainQueue CQ=CreateChainQueue();
    AddChainQ(CQ,5);
    AddChainQ(CQ,6);
    AddChainQ(CQ,7);
    PrintChainQ(CQ);
    DeleteChainQ(CQ);
    PrintChainQ(CQ);
    return 1;
}