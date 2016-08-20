#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5

int MinKey(int* key, int* mstSet){
    int min = INT_MAX, idx;

    for (int i = 0; i < N; i++){
        if (mstSet[i] == 0 && key[i] < min)
            min = key[i], idx = i;
    } 

    return idx;
}

void PrintMST(int* parent, int graph[N][N]){
    printf("Edge   Weight\n");
    for (int i = 1; i < N; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]); 
}

void PrimMST(int graph[N][N]){
    int key[N];
    int parent[N];
    int mstSet[N];

    for (int i = 0; i < N; i++){
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < N-1; i++){
        int u = MinKey(key, mstSet);    
        mstSet[u] = 1;

        for (int j = 0; j < N; j++){
            if (graph[u][j] && mstSet[j] == 0 && graph[u][j] < key[j])
                parent[j] = u, key[j] = graph[u][j];
        }
    }

    PrintMST(parent, graph);
}

int main()
{
   //* Let us create the following graph
          //2    3
      //(0)--(1)--(2)
       //|   / \   |
      //6| 8/   \5 |7
       //| /     \ |
      //(3)-------(4)
            //9          
   int graph[N][N] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    PrimMST(graph);
 
    return 0;
}

