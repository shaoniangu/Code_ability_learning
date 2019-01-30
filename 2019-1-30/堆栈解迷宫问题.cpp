#include <stdio.h>
#include <stdlib.h>

#define MAXMATRIXSIZE 10
#define MAXSTACKSIZE 100

typedef int Position;
typedef struct SNode * PtrToSNode;

struct Offsets
{
    short int Vert;
    short int Horiz;
};

struct MazePosition
{
    short int Row;
    short int Col;
    short int Dir;
};
typedef struct MazePosition ElementType;


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
        printf("ERROR:The stack is empty!\n");
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


void Path(int Maze[][MAXMATRIXSIZE], int EXITROW, int EXITCOL)
{
    struct Offsets Move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE]={0};
    Stack S;
    struct MazePosition P;
    short int Row,Col,NextRow,NextCol,Dir;
    bool Found=false;

    S = CreateStack(MAXSTACKSIZE);
    Mark[EXITROW][EXITCOL]=1;
    P.Row=EXITROW;
    P.Col=EXITCOL;
    P.Dir=0;
    Push(S,P);
    while(!isEmpty(S)&&!Found)
    {
        P=Pop(S);
        Row=P.Row;
        Col=P.Col;
        Dir=P.Dir;
        while(Dir<8 && !Found)
        {
            NextRow=Row+Move[Dir].Vert;
            NextCol=Col+Move[Dir].Horiz;
            if(NextRow==1&&NextCol==1)
                Found=true;
            else
            {
                if(!Maze[NextRow][NextCol]&&!Mark[NextRow][NextCol])
                {
                    Mark[NextRow][NextCol]=1;
                    P.Row=Row;
                    P.Col=Col;
                    P.Dir=Dir+1;    //存下一个方向的原因是，要存没有走过的方向，方便回溯；其实push已经当前方向也可以，只是代码要在move计算下一个位置的时候dir加1
                    Push(S,P);
                    Row=NextRow;
                    Col=NextCol;
                    Dir=0;
                }
                else
                    ++Dir;   
            }
        }
    }
    if(Found)
    {
        printf("The path is as follows：\n");
        printf("Row\tCol\n:");
        printf("1\t1");
        printf("%d\t%d\n",Row,Col);
        while(!(isEmpty(S)))
        {
            P=Pop(S);
            printf("%d\t%d\n",P.Row,P.Col);
        }
    }
    else
    {
        printf("There is no path!\n");
    }
}

int main()
{
    int Maze[MAXMATRIXSIZE][MAXMATRIXSIZE]={0};
    for (size_t i = 0; i < MAXMATRIXSIZE; i++)
    {
        for (size_t j = 0; j < MAXMATRIXSIZE; j++)
        {
            if(i==0 || j==0 || i==MAXMATRIXSIZE-1|| j==MAXMATRIXSIZE-1)
                Maze[i][j]=1;
            printf("%d ", Maze[i][j]);
        }
        printf("\n");
    }
    Path(Maze, 7, 7);
    return 1;
}