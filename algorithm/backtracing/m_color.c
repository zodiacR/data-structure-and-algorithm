#include <stdio.h>
#include <stdlib.h>

#define N 10

int IsSafe(int graph[N][N], int v, int *vertex, int color) {
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && vertex[i] == color) return 0;
    }

    return 1;
}

void PrintGrid(int vertex[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", vertex[i]);
    }
    printf("\n");
}

int MColorUtil(int graph[N][N], int v, int m, int *vertex) {
    if (v == N) return 1; 

    for (int i = 1; i <= m; i++) {
        if (IsSafe(graph, v, vertex, i)) {
            vertex[v] = i;
            if (MColorUtil(graph, v+1, m, vertex)) return 1;
            vertex[v] = 0;
        }
    }

    return 0;
}
void MColor(int graph[N][N], int m) {
    int vertex[N];

    for (int i = 0; i < N; i++) vertex[i] = 0;

    if (MColorUtil(graph, 0, m, vertex)) {
        PrintGrid(vertex);        
    }
    else {
        printf("No solution\n");
    }
}

int main()
{
    /* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    /*int graph[N][N] = {{0, 1, 1, 1},*/
        /*{1, 0, 1, 0},*/
        /*{1, 1, 0, 1},*/
        /*{1, 0, 1, 0},*/
    /*};*/
    int graph[N][N] = {
            {0,1,0,0,1,1,0,0,0,0},
            {1,0,1,0,0,0,1,0,0,0},
            {0,1,0,1,0,0,0,1,0,0},
            {0,0,1,0,1,0,0,0,1,0},
            {1,0,0,1,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,1,1,0},
            {0,1,0,0,0,0,0,0,1,1},
            {0,0,1,0,0,1,0,0,0,1},
            {0,0,0,1,0,1,1,0,0,0},
            {0,0,0,0,1,0,1,1,0,0}};

    int m = 3; // Number of colors
    MColor(graph, m);
    return 0;
}
