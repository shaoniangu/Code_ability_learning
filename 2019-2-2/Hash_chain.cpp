#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXTABLESIZE 100000
#define KEYLENGTH 15
typedef char ElementType[KEYLENGTH+1];
typedef int Index;


typedef struct LNode * PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode * HashTable;
struct TblNode
{
    int TableSize;
    List Heads;
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


HashTable Create(int TableSize)
{
    HashTable H;
    int i;
    H=(HashTable)malloc(sizeof(struct TblNode));
    H->TableSize=NextPrime(TableSize);

    H->Heads=(List)malloc(H->TableSize*sizeof(struct LNode));
    for (size_t i = 0; i < H->TableSize; i++)
    {
        H->Heads[i].Data[0]='\0';
        H->Heads[i].Next=NULL;
    }
    return H;
}

int Hash(const char *Key, int TableSize)
{
    unsigned int H=0;
    while(*Key!='\0')
    {
        H=(H<<5)+*Key++;
    }
    return H%TableSize;
}

Position Find(HashTable H, ElementType Key)
{
    Position P;
    Index Pos;
    Pos=Hash(Key, H->TableSize);
    P=H->Heads[Pos].Next;
    while(P&&strcmp(P->Data, Key))
        P=P->Next;
    return P;
}

bool Insert(HashTable H, ElementType Key)
{
    Position P, NewCell;
    Index Pos;
    P=Find(H,Key);

    if(!P)
    {
        NewCell=(Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        Pos=Hash(Key,H->TableSize);
        NewCell->Next=H->Heads[Pos].Next;
        H->Heads[Pos].Next=NewCell;
        return true;
    }
    else
    {
        printf("¼üÖµÒÑ´æÔÚ");
        return false;
    }
}

void DestroyTable(HashTable H)
{
    int i;
    Position P,Tmp;
    for(i=0;i<H->TableSize;i++)
    {
        P=H->Heads[i].Next;
        while(P)
        {
            Tmp=P->Next;
            free(P);
            P=Tmp;
        }
    }
    free(H->Heads);
    free(H);
}

int main()
{
    return 1;
}