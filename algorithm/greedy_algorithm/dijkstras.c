#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 9

int MinDistance(int* dist, int* spt) {
    int idx, min = INT_MAX;

    for (int i = 0; i < V; i++){
        if (!spt[i] && dist[i] < min){
            min = dist[i];
            idx = i; 
        }
    }

    return idx;
}

void PrintSolution(int* dist, int src){
    for (int i = 0 ; i < V; i++){
        if (src != i)
            printf("%d - %d: %d\n", src, i, dist[i]);
    } 
}

void Dijkstra(int graph[V][V], int src) {
    int spt[V];
    int distance[V];

    for (int i = 0; i < V; i++){
        spt[i] = 0;
        distance[i] = INT_MAX;
    }

    distance[src] = 0;

    for (int i = 0; i < V-1; i++){
        int u = MinDistance(distance, spt);
        spt[u] = 1;

        for (int v = 0; v < V; v++){
            if (!spt[v] && graph[u][v] &&
                    distance[u] != INT_MAX &&
                        distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
        }
    }

    PrintSolution(distance, src);

}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    Dijkstra(graph, 5);
 
    return 0;
}
