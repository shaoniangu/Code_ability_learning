#include <stdio.h>
#include <stdlib.h>
#define Error -1
typedef int Position;
typedef struct SNode * PtrToSNode;
typedef int ElementType;


struct SNode{
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(Maxsize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = Maxsize;
    return S;
}

bool isFull(Stack S)
{
    return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, ElementType x)
{
    if (isFull(S))
    {
        printf("The stack is full!");
        return false;
    }
    else
    {
        S->Data[++(S->Top)]=x;
        return true;
    }
}

bool isEmpty(Stack S)
{
    return(S->Top == -1);
}

ElementType Pop(Stack S)
{
    if(isEmpty(S))
    {
        printf("The stack is empty!");
        return Error;
    }
    else
    {
        return (S->Data[(S->Top)--]);
    }
}

void PrintStack(Stack S)
{
    Position temp = S->Top;
    while(temp != -1)
    {
        printf("%d ",S->Data[temp--]);
    }
    printf("\n");
}


typedef struct ChainSNode * PtrToChainSNode;

struct ChainSNode 
{
    ElementType Data;
    PtrToChainSNode Next;
};
typedef PtrToChainSNode ChainStack;

ChainStack CreateChainStack()
{
    ChainStack S;
    S=(ChainStack)malloc(sizeof(struct ChainSNode));
    S->Next=NULL;
    return S;
}

bool isChainStackEmpty(ChainStack S)
{
    return (S->Next == NULL);
}

bool PushChainStack(ChainStack S, ElementType x)
{
    ChainStack temp;
    temp = (ChainStack)malloc(sizeof(struct ChainSNode));
    temp->Data=x;
    temp->Next=S->Next;
    S->Next = temp;
    return true;
}

ElementType PopChainStack(ChainStack S)
{
    ChainStack firstcell;
    if(isChainStackEmpty(S))
    {
        printf("The ChainStack is empty!\n");
        return Error;
    }
    else
    {
        firstcell=S->Next;
        S->Next=firstcell->Next;
        ElementType firstelement = firstcell->Data;
        free(firstcell);
        return firstelement;
    }
}

void PrintChainStack(ChainStack S)
{
    ChainStack temp=S;
    while(temp->Next!=NULL)
    {
        temp = temp->Next;
        printf("%d ",temp->Data);
    }
    printf("\n");
}

int main()
{
    Stack S=CreateStack(10);
    Push(S,0);
    Push(S,1);
    Push(S,2);
    PrintStack(S);
    Pop(S);
    PrintStack(S);

    ChainStack CS=CreateChainStack();
    PushChainStack(CS,5);
    PushChainStack(CS,6);
    PushChainStack(CS,7);
    PrintChainStack(CS);
    PopChainStack(CS);
    PrintChainStack(CS);

    return 0;
}