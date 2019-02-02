#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct GNode * PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};

typedef PtrToGNode MGraph;

typedef struct ENode * PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++)
        for(W=0;W<Graph->Nv;W++)
        {
            Graph->G[V][W]=INFINITY;
        }
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight; // 无向图
}


MGraph BuildGraph()
{
    MGraph Graph;
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
        scanf("%c", &(Graph->Data[V])); 
    }
    return Graph;
}

void PrintGraph(MGraph Graph)
{
    int i,j;
    for(i=0;i<Graph->Nv;i++)  
    {
         for(j=0;j<Graph->Nv;j++)
        {
            printf("%d\t", Graph->G[i][j]);
        }
    printf("\n");
    }
}

int main()
{
    MGraph Graph=BuildGraph();
    PrintGraph(Graph);
    return 1;
}