#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct edge{
    int src;
    int dest;
}Edge;

typedef struct graph{
    int V;
    int E;
    Edge* edge;
}Graph;

int Find(int* parent, int i){
    if (parent[i] == -1) return i;
    return Find(parent, parent[i]);
}

void Union(int *parent, int x, int y) {
    int xset = Find(parent, x);
    int yset = Find(parent, y);
    parent[xset] = yset;
}

Graph* CreateGraph(int v, int e){
    Graph* g = (Graph*)malloc(sizeof(struct graph));
    g->E = e;
    g->V = v;
    g->edge = (Edge*)malloc(sizeof(struct edge) * e);

    return g;
}

int IsCycle(Graph *g){
    int *parent = (int*)malloc(sizeof(int) * g->V);
    memset(parent, -1, sizeof(int) * g->V);

    for (int i = 0; i < g->E; i++){
        int x = Find(parent, g->edge[i].src);
        int y = Find(parent, g->edge[i].dest);
        if ( x == y) return 1;

        Union(parent, x, y);
    }

    return 0;
}

// Driver program to test above functions
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
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    /*graph->edge[2].src = 0;*/
    /*graph->edge[2].dest = 2;*/
 
    if (IsCycle(graph))
        printf( "graph contains cycle\n" );
    else
        printf( "graph doesn't contain cycle\n" );
 
    return 0;
}
