#include <cstdio>
#include <cstdlib>
#define MAX_VERTEX 30

typedef struct graphType
{
    int n;                                  // the number of vertex
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];  // 30 x 30
}graphType;

void CreateGraph(graphType *g)
{
    int i, j;
    g->n = 0;
    for (i = 0; i < MAX_VERTEX; ++i)
    {
        for (j = 0; j < MAX_VERTEX; ++j)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void insertVertex(graphType* g, int v)
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
    if (u >= g->n || v >= g->n)
    {
        printf("\n 그래프에 없는 정점\n");
        return;
    }

    g->adjMatrix[u][v] = 1;
}

void printAdjMatrix(graphType *g)
{
    int i, j;
    for (i = 0; i < g->n; ++i)
    {
        printf("\n\t\t");
        for (j = 0; j < g->n; ++j)
        {
            printf("%2d", g->adjMatrix[i][j]);
        }
    }
}

int main(void)
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

    insertEdge(G1, 0, 1);
    insertEdge(G1, 0, 3);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 3, 0);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 2);

    printf("\n G1의 인접 행렬\n");
    printAdjMatrix(G1);

    for (i = 0; i < 3; ++i)
    {
        insertVertex(G2, i);
    }

    insertEdge(G2, 0, 1);
    insertEdge(G2, 0, 2);
    insertEdge(G2, 1, 0);
    insertEdge(G2, 1, 2);
    insertEdge(G2, 2, 0);
    insertEdge(G2, 2, 1);

    printf("\n G2의 인접 행렬\n");
    printAdjMatrix(G2);

    for (i = 0; i < 4; ++i)
    {
        insertVertex(G3, i);
    }

    insertEdge(G3, 0, 1);
    insertEdge(G3, 0, 3);
    insertEdge(G3, 1, 2);
    insertEdge(G3, 1, 3);
    insertEdge(G3, 2, 3);

    printf("\n G3의 인접 행렬\n");
    printAdjMatrix(G3);

    for (i = 0; i < 3; ++i)
    {
        insertVertex(G4, i);
    }

    insertEdge(G4, 0, 1);
    insertEdge(G4, 0, 3);
    insertEdge(G4, 1, 0);
    insertEdge(G4, 1, 2);

    printf("\n G4의 인접 행렬\n");
    printAdjMatrix(G4);

    return 0;
}
