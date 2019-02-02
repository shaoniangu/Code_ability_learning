#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXTABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;

typedef enum {Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell;
struct HashEntry
{
    ElementType Data;
    EntryType Info;
};

typedef struct TblNode * HashTable;
struct TblNode
{
    int TableSize;
    Cell * Cells;
};

int NextPrime(int N)
{
    int i,p=(N%2)?N+2:N+1;
    while(p<=MAXTABLESIZE)
    {
        for(i=(int)sqrt(p);i>2;i--)
        {
            if(!(p%i))  break;
        }
        if(i==2)
            break;
        else
        {
            p+=2;
        }
    }
    return p;
}


HashTable CreateTable(int TableSize)
{
    HashTable H;
    int i;
    H=(HashTable)malloc(sizeof(struct TblNode));
    H->TableSize=NextPrime(TableSize);
    H->Cells=(Cell *)malloc(H->TableSize*sizeof(Cell));
    for(i=0;i<H->TableSize;i++)
        H->Cells[i].Info=Empty;
    return H;
}

Position Hash(ElementType Key, int p)
{
    return Key % p;
}

Position Find(HashTable H, ElementType Key)
{
    Position CurrentPos, NewPos;
    int CNum=0;

    NewPos=CurrentPos=Hash(Key, H->TableSize);

    while(H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key)
    {
        if(++CNum%2)
        {
            NewPos=CurrentPos+(CNum+1)*(CNum+1)/4;
            if(NewPos>=H->TableSize)
                NewPos=NewPos%H->TableSize;
        }
        else
        {
            NewPos=CurrentPos-CNum*CNum/4;
            while(NewPos<0)
                NewPos+=H->TableSize;
        }
    }
    return NewPos;
}


bool Insert(HashTable H, ElementType Key)
{
    Position Pos=Find(H,Key);

    if(H->Cells[Pos].Info!=Legitimate)
    {
        H->Cells[Pos].Info=Legitimate;
        H->Cells[Pos].Data=Key;
        return true;
    }
    else
    {
        printf("¼üÖµÒÑ´æÔÚ");
        return false;
    }
}

int main()
{
    return 1;
}