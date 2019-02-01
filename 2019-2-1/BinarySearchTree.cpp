#include <stdio.h>
#include <stdlib.h>
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

Position Find(BinTree BST, ElementType x)
{
    if(!BST)
    {
        return NULL;
    }
    if(x>BST->Data)
    {
        return Find(BST->Right, x);
    }
    else if (x<BST->Data)
    {
        return Find(BST->Left, x);
    }
    else
    {
        return BST;
    }
}

Position Find2(BinTree BST, ElementType x)
{
    BinTree temp=BST;
    while(temp)
    {
        if(x>temp->Data)
        {
            temp=temp->Right;
        }
        else if (x<temp->Data)
        {
            temp=temp->Left;
        }
        else
        {
           break;
        }
    }
    return temp;
}

Position FindMin(BinTree BST)
{
    if(!BST) return NULL;
    else if (!BST->Left)
    {
        return BST;
    }
    else
    {
        return FindMin(BST->Left);
    }
}

Position FindMax(BinTree BST)
{
    BinTree temp=BST;
    if(!temp) return NULL;
    while(temp->Right)
    {
        temp=temp->Right;
    }
    return temp;
}

Position Insert(BinTree BST, ElementType x)
{
    if(!BST)
    {
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=x;
        BST->Left=BST->Right=NULL;
    }
    else
    {
        if(x<BST->Data)
            BST->Left=Insert(BST->Left,x);
        else if (x>BST->Data)
        {
            BST->Right=Insert(BST->Right,x);
        }
    }
    return BST;
}

Position Delete(BinTree BST, ElementType x)
{
    Position Tmp;
    if(!BST)
    {
        printf("No element %c!\n",x);
    }
    else
    {
        if(x<BST->Data)
        {
            BST->Left=Delete(BST->Left,x);
        }
        else if(x>BST->Data)
        {
            BST->Right=Delete(BST->Right,x);
        }
        else
        {
            if(BST->Left && BST->Right)
            {
                Tmp=FindMin(BST->Right);
                BST->Data=Tmp->Data;
                BST->Right=Delete(BST->Right,BST->Data);
            }
            else
            {
                Tmp=BST;
                if(!BST->Left)
                    BST=BST->Right;
                else
                {
                    BST=BST->Left;
                }            
                free(Tmp);
            }
        }
    }
    return BST;
}

int main()
{
    BinTree BST=NULL;
    BST=Insert(BST,'d');
    BST=Insert(BST,'c');
    BST=Insert(BST,'e');
    BST=Insert(BST,'a');
    BST=Insert(BST,'b');
    BST=Insert(BST,'g');
    BST=Insert(BST,'h');
    BST=Insert(BST,'f');
    BinTree res, min,max;
    res=Find(BST, 'f');
    max=FindMax(BST);
    min=FindMin(BST);
    printf("%c, %c, %c\n", res->Data, max->Data, min->Data);

    BST=Delete(BST,'h');
    max=FindMax(BST);
    min=FindMin(BST);
    printf("%c, %c\n", max->Data, min->Data);
    return 1;
}