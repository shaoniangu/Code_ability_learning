#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 1000

// ���´��벢����������Ҫʵ��ElementTypeΪHuffmanTree����С�ѣ����Ը�����������������
typedef struct HTNode * HuffmanTree;
struct HTNode
{
    int Weight;
    HuffmanTree Left;
    HuffmanTree Right;
};

HuffmanTree Huffman(MinHeap H)
{
    int i,N;
    HuffmanTree T;
    BuildHeap(H); //������С�ѣ�����ʡ��
    N=H->Size;

    for(i=1;i<N;i++)
    {
        T=(HuffmanTree)malloc(sizeof(struct HTNode));
        T->Left=DeleteMin(H);
        T->Right=DeleteMin(H);
        T->Weight=T->Left->Weight + T->Right->Weight;
        Insert(H,T);
    }
    return DeleteMin(H);
}