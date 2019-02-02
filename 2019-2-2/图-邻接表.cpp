#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode * PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};

typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;
    
    return Graph;
}


void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;

    //无向图
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V1;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge=NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    DataType c;

    printf("请输入顶点个数：");
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    printf("请输入边数：");
    scanf("%d",&Graph->Ne);

    if(Graph->Ne !=0)
    {
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++)
        {
            printf("请输入边的起始顶点、终止定点和权重，用空格隔开：");
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph, E);
        }
    }
    for(V=0;V<Graph->Nv;V++)
    {    while ((c = getchar()) != EOF && c != '\n');
        printf("请输入%d顶点数据：", V+1);
        scanf("%c", &(Graph->G[V].Data)); 
    }
    return Graph;
}

void PrintLGraph(LGraph Graph)
{
    int i;
    PtrToAdjVNode p;
    for(i=0;i<Graph->Nv;i++)
    {   
        p = Graph->G[i].FirstEdge;
        printf("顶点%d的领接点： ",i);
        while(p)
        {
            printf("vertex %d,weight %d\t", p->AdjV,p->Weight);
            p=p->Next;
        }
        printf("\n");
    }
}

int main()
{
    LGraph Graph=BuildGraph();
    PrintLGraph(Graph);
    return 1;
}