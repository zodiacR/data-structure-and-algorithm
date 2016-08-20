#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge{
    int src, dest;
}Edge;

typedef struct graph{
    int V, E;
    Edge *edges;
}Graph;

Graph* CreateGraph(int v, int e){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->E = e;
    g->V = v;
    g->edges = (Edge*)malloc(e * sizeof(Edge));

    return g;
}

int Find(int* parent, int i){
    if (parent[i] == -1) return i; 

    return Find(parent, parent[i]);
}

void Union(int *parent, int x, int y){
    int x_parent = Find(parent, x);
    int y_parent = Find(parent, y);

    parent[x_parent] = y_parent;
}

int IsCycle(Graph *g) {
    int *parent = (int *)malloc(g->V * sizeof(int));

    memset(parent, -1, sizeof(int) * g->V);

    for (int i = 0; i < g->E; i++){
        int x = Find(parent, g->edges[i].src);
        int y = Find(parent, g->edges[i].dest);

        if (x == y) return 1;

        Union(parent, x, y);
    }

    return 0;
}

int main()
{
    /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */    
    int V = 3, E = 2;
    Graph* graph = CreateGraph(V, E);
 
    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
 
    // add edges 1-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
 
    // add edges 0-2
    /*graph->edges[2].src = 0;*/
    /*graph->edges[2].dest = 2;*/
 
    if (IsCycle(graph))
        printf( "graph contains cycle\n" );
    else
        printf( "graph doesn't contain cycle\n" );
 
    return 0;
}

