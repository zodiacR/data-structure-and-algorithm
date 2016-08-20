#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge{
    int src;
    int dest;
    int weight;
}Edge;

typedef struct graph{
    int V;
    int E;
    Edge *edges;
}Graph;

Graph* CreateGraph(int V, int E){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->E = E;

    g->edges = (Edge*)malloc(sizeof(Edge) * E);

    return g;
}

void printDistance(int n, int *dist, int start){
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d-->%d \t\t %d\n", start, i, dist[i]);   
}

void Bellman_Ford(Graph* g, int start) {
    int *dist = (int*)malloc(sizeof(int) * g->V);    

    for (int i = 0; i < g->V; i++) dist[i] = INT_MAX;

    dist[start] = 0;

    for (int i = 0; i < g->V-1; i++){
        for (int j = 0; j < g->E; j++) {
            int u = g->edges[j].src;
            int v = g->edges[j].dest;
            int weight = g->edges[j].weight;

            if (dist[u] != INT_MAX && dist[v] > weight + dist[u])
                dist[v] = weight + dist[u];
        }
    }

    for (int i = 0; i < g->E; i++) {
        int u = g->edges[i].src; 
        int v = g->edges[i].dest; 
        int weight = g->edges[i].weight; 

        if (dist[u] != INT_MAX && dist[v] > weight + dist[u])
            printf("There exits negative cycle\n");
    }

    printDistance(g->V, dist, start);

}

// Driver program to test above functions
int main()
{
    /* Let us create the graph given in above example */
    int V = 6;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph = CreateGraph(V, E);
 
    // add edge 0-1 (or S-E in above figure)
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 8;
 
    // add edges 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 10;
 
    // add edges 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 1;
 
    // add edges 1-3 (or B-D in above figure)
    graph->edges[3].src = 3;
    graph->edges[3].dest = 2;
    graph->edges[3].weight = -4;
 
    // add edges 1-4 (or A-E in above figure)
    graph->edges[4].src = 3;
    graph->edges[4].dest = 5;
    graph->edges[4].weight = -1;
 
    // add edges 3-2 (or D-C in above figure)
    graph->edges[5].src = 2;
    graph->edges[5].dest = 5;
    graph->edges[5].weight = 2;
 
    // add edges 3-1 (or D-B in above figure)
    graph->edges[6].src = 4;
    graph->edges[6].dest = 2;
    graph->edges[6].weight = 1;
 
    // add edges 4-3 (or E-D in above figure)
    graph->edges[7].src = 5;
    graph->edges[7].dest = 4;
    graph->edges[7].weight = -2;
 
    Bellman_Ford(graph, 0);
 
    return 0;
}
