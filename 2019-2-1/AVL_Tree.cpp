#include <stdio.h>
#include <stdlib.h>
typedef struct AVLNode * Position;
typedef Position AVLTree;
typedef char ElementType;

struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a,int b)
{
    return a>b?a:b;
}

int GetHeight(AVLTree BT)
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

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left), GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left), A->Height)+1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B=A->Right;
    A->Right=B->Left;
    B->Left=A;
    A->Height=Max(GetHeight(A->Left), GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Right), A->Height)+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left=SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right=SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, ElementType x)
{
    if(!T)
    {
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->Data=x;
        T->Left=T->Right=NULL;
        T->Height=1;
    }
    else if (x<T->Data)
    {
        T->Left=Insert(T->Left,x);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2)
        {
            if(x<T->Left->Data)
            {
                T=SingleLeftRotation(T);
            }
            else
            {
                T=DoubleLeftRightRotation(T);
            }
        }
    }
    else if (x>T->Data)
    {
        T->Right=Insert(T->Right,x);
        if(GetHeight(T->Left)-GetHeight(T->Right)==-2)
        {
            if(x>T->Right->Data)
            {
                T=SingleRightRotation(T);
            }
            else
            {
                T=DoubleRightLeftRotation(T);
            }
        }
    }
    T->Height=Max(GetHeight(T->Left), GetHeight(T->Right))+1;
    return T;
}