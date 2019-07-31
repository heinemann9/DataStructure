#include <cstdio>
#include <cstdlib>
#define MAX_VERTEX 30

typedef struct graphNode
{
    int vertex;
    struct graphNode *link;
}graphNode;

typedef struct graphType
{
    int n;                              // the number of vertex
    graphNode *adjList_H[MAX_VERTEX];   // head pointer arr
}graphType;


void CreateGraph(graphType *g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; ++v)
    {
        g->adjList_H[v] = NULL;
    }
}

void insertVertex(graphType *g, int v)
{
    if (((g->n) + 1) > MAX_VERTEX)
    {
        printf("\n 그래프 정점 개수 초과\n");
        return;
    }

    ++g->n;
}

// (u, v)
void insertEdge(graphType *g, int u, int v)
{
    graphNode *node;

    if (u >= g->n || v >= g->n)
    {
        printf("\n 그래프에 없는 정점\n");
        return;
    }

    node = new graphNode();
    node->vertex = v;
    node->link = g->adjList_H[u];
    g->adjList_H[u] = node;
}

void printAdjList(graphType *g)
{
    int i;
    graphNode *p;
    for (i = 0; i < g->n; ++i)
    {
        printf("\n\t\t정점%c의 인접 리스트", i + 65);
        p = g->adjList_H[i];
        while (p)
        {
            printf(" -> %c", p-> vertex + 65);
            p = p->link;
        }
    }
}

int main()
{
    int i;
    graphType *G1, *G2, *G3, *G4;

    G1 = new graphType();
    G2 = new graphType();
    G3 = new graphType();
    G4 = new graphType();

    CreateGraph(G1);
    CreateGraph(G2);
    CreateGraph(G3);
    CreateGraph(G4);

    for (i = 0; i < 4; ++i)
    {
        insertVertex(G1, i);
    }

    insertEdge(G1, 0, 3);
    insertEdge(G1, 0, 1);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 3, 2);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 0);

    printf("\n G1의 인접 리스트\n");
    printAdjList(G1);

    for (i = 0; i < 3; ++i)
    {
        insertVertex(G2, i);
    }

    insertEdge(G2, 0, 2);
    insertEdge(G2, 0, 1);
    insertEdge(G2, 1, 2);
    insertEdge(G2, 1, 0);
    insertEdge(G2, 2, 1);
    insertEdge(G2, 2, 0);

    printf("\n G2의 인접 행렬\n");
    printAdjList(G2);

    for (i = 0; i < 4; ++i)
    {
        insertVertex(G3, i);
    }

    insertEdge(G3, 0, 3);
    insertEdge(G3, 0, 1);
    insertEdge(G3, 1, 3);
    insertEdge(G3, 1, 2);
    insertEdge(G3, 2, 3);

    printf("\n G3의 인접 행렬\n");
    printAdjList(G3);

    for (i = 0; i < 3; ++i)
    {
        insertVertex(G4, i);
    }

    insertEdge(G4, 0, 2);
    insertEdge(G4, 0, 1);
    insertEdge(G4, 1, 2);
    insertEdge(G4, 1, 0);

    printf("\n G4의 인접 행렬\n");
    printAdjList(G4);

    return 0;
}
