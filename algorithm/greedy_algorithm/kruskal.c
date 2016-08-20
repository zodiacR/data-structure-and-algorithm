#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct edge{
    int src;
    int dest;
    int weight;
}Edge;

typedef struct graph{
    int V;
    int E;
    Edge* edge;
}Graph;

Graph* CreateGraph(int v, int e){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->E = e;
    g->V = v;
    g->edge = (Edge*)malloc(sizeof(Edge) * e);

    return g;
}

typedef struct subset{
    int parent;
    int rank;
}Subset;

int Find(Subset *subsets, int i){
    if (subsets[i].parent != i)
        subsets[i].parent = Find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(Subset* subsets, int x, int y){
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int cmp(const void*a, const void *b){
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void KruskalMST(Graph* g){
    int V = g->V;
    Subset* subsets = (Subset*)malloc(sizeof(subsets) * g->V); 

    for (int i = 0; i < g->V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int i = 0;
    int e = 0;

    Edge result[V-1];

    while (e < V-1){
        Edge next = g->edge[i++];

        int x = Find(subsets, next.src);
        int y = Find(subsets, next.dest);

        if (x != y){
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
}

// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V;  // Number of vertices in graph
    int E;  // Number of edges in graph
    scanf("%d %d", &V, &E);
    Graph* graph = CreateGraph(V, E);
 
    for (int e = 0; e < E; e++){
        scanf("%d", &(graph->edge[e].weight));
        scanf("%d", &(graph->edge[e].src));
        scanf("%d", &(graph->edge[e].dest));
    } 

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);
    for (int e = 0; e < E; e++){
        printf("%d----%d=%d\n", graph->edge[e].src,
                                graph->edge[e].dest,
                                graph->edge[e].weight);
    } 
    KruskalMST(graph);
 
    return 0;
}
