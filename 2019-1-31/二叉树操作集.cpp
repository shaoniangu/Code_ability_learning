#include <stdio.h>
#include <stdlib.h>
#define StackError NULL
#define QueueError NULL

typedef struct TNode * Position;
typedef Position BinTree;
typedef char ElementType;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InorderTraversal(BinTree BT)
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf("The node value is %c.\n", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("The node value is %c.\n", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal(BinTree BT)
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("The node value is %c.\n", BT->Data);
    }
}

// �ǵݹ�ʵ�ֶ���������������㷨��ʹ�ö�ջ
typedef int PositionStack;
typedef struct SNode * PtrToSNode;
typedef BinTree StackElementType;


struct SNode{
    StackElementType * Data;
    PositionStack Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (StackElementType*)malloc(Maxsize*sizeof(StackElementType));
    S->Top = -1;
    S->MaxSize = Maxsize;
    return S;
}

bool isFullStack(Stack S)
{
    return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, StackElementType x)
{
    if (isFullStack(S))
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

bool isEmptyStack(Stack S)
{
    return(S->Top == -1);
}

StackElementType Pop(Stack S)
{
    if(isEmptyStack(S))
    {
        printf("The stack is empty!");
        return StackError;
    }
    else
    {
        return (S->Data[(S->Top)--]);
    }
}

void PrintStack(Stack S)
{
    PositionStack temp = S->Top;
    while(temp != -1)
    {
        printf("%c ",S->Data[temp--]);
    }
    printf("\n");
}

// ���ö�ջ�ǵݹ�ʵ���������
void InorderTraversal2(BinTree BT)
{
    BinTree T;
    Stack S=CreateStack(100);
    T=BT;
    while(T || !isEmptyStack(S))
    {
        while(T)
        {
            Push(S,T);
            T=T->Left;
        }
        T=Pop(S);
        printf("The node value is %c.\n", T->Data);
        T=T->Right;
    }
}

//����ʵ�ֲ������
typedef struct QNode *PtrToQNode;
typedef int QueuePosition;
typedef BinTree QueueElementType;
struct QNode
{
    QueueElementType *Data;
    QueuePosition Front, Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;


Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (QueueElementType*)malloc(MaxSize*sizeof(QueueElementType));
    Q->Front = Q->Rear =0;
    Q->MaxSize=MaxSize;   
    return Q;
}

bool isFullQueue(Queue Q)
{
    return ((Q->Rear + 1)%Q->MaxSize==Q->Front);
}

bool isEmptyQueue(Queue Q)
{
    return (Q->Front == Q->Rear);
}

bool AddQ(Queue Q, QueueElementType x)
{
    if(isFullQueue(Q))
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

QueueElementType DeleteQ(Queue Q)
{
    if(isEmptyQueue(Q))
    {
        printf("The queue is empty!\n");
        return QueueError;
    }
    else
    {
        Q->Front=(Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];
    }
}

void PrintQ(Queue Q)
{
    QueuePosition front=Q->Front;
    QueuePosition rear = Q->Rear;
    while(front!=rear)
    {
        front = (front+1)%Q->MaxSize;
        printf("%c ",Q->Data[front]);
    }
    printf("\n");
}

// ���ö���ʵ�ֲ������
void LevelorderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if (!BT) return;
    Q = CreateQueue(100);
    AddQ(Q,BT);
    while(!isEmptyQueue(Q))
    {
        T=DeleteQ(Q);
        printf("The node value is %c.\n", T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}

void GetLeafNode(BinTree BT)
{
    if(BT)
    {
        if (!BT->Left && !BT->Right)
            printf("The node value is %c.\n", BT->Data);
        GetLeafNode(BT->Left);
        GetLeafNode(BT->Right);
    }
}

int GetHeight(BinTree BT)
{
    int HL,HR,MAXH;
    if(BT)
    {
        HL=GetHeight(BT->Left);
        HR=GetHeight(BT->Right);
        MAXH=HL>HR?HL:HR;
        return (MAXH+1);
    }
    else
    {
        return 0;
    }
}

#define NoInfo '0'

BinTree CreateBinTree()
{
    ElementType Data;
    BinTree BT, T;
    Queue Q=CreateQueue(100);
    printf("����������ֵ���ս��������0��");
    scanf("%c", &Data);
    getchar();

    if(Data!=NoInfo)
    {
        BT=(BinTree)malloc(sizeof(struct TNode));
        BT->Data=Data;
        BT->Left=BT->Right=NULL;
        AddQ(Q,BT);
    }
    else
    {
        return NULL;
    }
    while(!isEmptyQueue(Q))
    {
        T=DeleteQ(Q);
        printf("������%c����Ҷ�ӽ��ֵ���սڵ�������0��",T->Data);
        scanf("%c",&Data);
        getchar();

        if(Data==NoInfo)
        {
            T->Left=NULL;
        }
        else
        {
            T->Left=(BinTree)malloc(sizeof(struct TNode));
            T->Left->Data=Data;
            T->Left->Left=T->Left->Right=NULL;
            AddQ(Q,T->Left);
        }
        printf("������%c����Ҷ�ӽ��ֵ���սڵ�������0��",T->Data);
        scanf("%c",&Data);
        getchar();

        if(Data==NoInfo)
        {
            T->Right=NULL;
        }
        else
        {
            T->Right=(BinTree)malloc(sizeof(struct TNode));
            T->Right->Data=Data;
            T->Right->Left=T->Right->Right=NULL;
            AddQ(Q,T->Right);
        }
    }
    return BT;
}

int main()
{
    BinTree BT=CreateBinTree();
    printf("************�������************\n");
    PreorderTraversal(BT);
    printf("************�������************\n");
    InorderTraversal(BT);
    printf("************�������************\n");
    PostorderTraversal(BT);
    printf("************���ö�ջ�ǵݹ�ʵ���������************\n");
    InorderTraversal2(BT);
    printf("************�������************\n");
    LevelorderTraversal(BT);
    printf("************��ȡҶ�ڵ�************\n");
    GetLeafNode(BT);
    printf("************��ȡ�߶�************\n");
    int height=GetHeight(BT);
    printf("%d",height);
}