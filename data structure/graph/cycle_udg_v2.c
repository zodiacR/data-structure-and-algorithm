#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int src, dest;
}Edge;

typedef struct graph{
    int V, E;
    Edge *edges;
}Graph;

struct subset{
    int rank;
    int parent;
};

int Find(struct subset *subsets, int i){
    if (subsets[i].parent != i)
        subsets[i].parent = Find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset *subsets, int x, int y){
    int x_root = Find(subsets, x);
    int y_root = Find(subsets, y);

    if (subsets[x_root].rank < subsets[y_root].rank){
        subsets[x_root].parent = y_root;
    }
    else if (subsets[x_root].rank > subsets[y_root].rank){
        subsets[y_root].parent = x_root;
    }
    else{
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
}

Graph* CreateGraph(int v, int e){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = v;
    graph->E = e;
    graph->edges = (Edge*)malloc(e * sizeof(Edge));

    return graph;
}

void PrintSubset(struct subset* subsets, int n){
    for(int i = 0; i < n; i++){
        printf("%d: parent:%d rank: %d\n", i,
                                           subsets[i].parent,
                                           subsets[i].rank);
    }
}

int IsCycle(Graph *g){
    struct subset* subsets = (struct subset*)malloc(sizeof(struct subset) * g->V); 

    for(int i = 0; i < g->V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for(int i = 0; i < g->E; i++){
        int x = Find(subsets, g->edges[i].src);
        int y = Find(subsets, g->edges[i].dest);

        if (x == y) return 1;

        Union(subsets, x, y);
        PrintSubset(subsets, g->V);
    }

    return 0;
}

int main(){

    int v, e;

    scanf("%d %d", &v, &e);
    Graph* graph = CreateGraph(v, e);

    for (int i = 0; i < e; i++){
        scanf("%d %d", &graph->edges[i].src,
                       &graph->edges[i].dest);
    }


    if (IsCycle(graph))
        printf("Graph contains a cycle\n");
    else
        printf("Graph doesn't contain a cycle\n");
}
