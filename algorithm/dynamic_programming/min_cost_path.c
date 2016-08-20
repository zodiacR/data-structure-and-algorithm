#include <stdio.h>
#include <stdlib.h>
#define R 3

int min(int a, int b, int c){
    if (a < b) return (a < c) ? a:c;
    else return (b < c) ? b:c;
}

int MCP(int matrix[][R], int n, int m){
    int cost[n+1][m+1];
    
    cost[0][0] = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0) cost[i][j] = cost[i][j-1] + matrix[i][j-1];
            else if (j == 0) cost[i][j] = cost[i-1][j] + matrix[i-1][j];
            else cost[i][j] = min(cost[i-1][j], cost[i][j-1], cost[i-1][j-1]) + matrix[i-1][j-1];
        }
    }

    return cost[n][m];
}

/* Driver program to test above functions */
int main()
{
   int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d \n", MCP(cost, 3, 3));
   return 0;
}
