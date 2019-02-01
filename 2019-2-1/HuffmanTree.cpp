#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 1000

// 如下代码并不完整，需要实现ElementType为HuffmanTree的最小堆，用以辅助哈夫曼树的生成
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
    BuildHeap(H); //建立最小堆，代码省略
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