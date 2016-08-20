#include <stdio.h>
#include <stdlib.h>

#define N 5

int IsSafe(int graph[N][N], int v, int *path, int u) {
    if (graph[path[u-1]][v] == 0) return 0;
    else {
        for (int i = 0; i < u; i++) {
            if (path[i] == v) return 0;
        }
        return 1;
    }
}

int HamCycleUtil(int graph[N][N], int *path, int pos) {
    if (pos == N) {
        if (graph[path[pos-1]][0]) return 1;
        else return 0;
    }

    else {
        for (int i = 1; i < N; i++) {
            if (IsSafe(graph, i, path, pos)){
                path[pos] = i;
                if (HamCycleUtil(graph, path, pos+1)) return 1;
                path[pos] = -1;
            }
        }

        return 0;
    }
}

void HamCycle(int graph[N][N]){
    int path[N];

    for (int i = 0; i < N; i++) path[i] = -1;

    path[0] = 0;

    if (HamCycleUtil(graph, path, 1)) {
        for (int i = 0; i < N; i++) printf("%d ", path[i]);
        printf("\n");
    } else printf("No solution\n");
}

// driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   int graph1[N][N] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    HamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    int graph2[N][N] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    HamCycle(graph2);
 
    return 0;
}
