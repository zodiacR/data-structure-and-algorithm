#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b){
    return a<b?a:b;
}

int EditDistance(char *A, char *B, int m, int n) {
    int dist[m+1][n+1];
    printf("str1: %s str2:%s\n", A, B);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dist[i][j] = j;
            }

            else if (j == 0) {
                dist[i][j] = i;
            }

            else if (A[i-1] == B[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                dist[i][j] = 1+ min(min(dist[i-1][j],
                                          dist[i][j-1]),
                                      dist[i-1][j-1]);
                /*printf("dist[%d][%d]: %d\n", i, j , dist[i][j]);*/
            }
        }
    }

    /*for (int i = 0; i <= m; i++) {*/
        /*for (int j = 0; j <= n; j++) {*/
            /*printf("%d ", dist[i][j]);*/
        /*}*/
        /*printf("\n");*/
    /*}*/

    return dist[m][n];
}

// Driver program
int main()
{
    // your code goes here
    char str1[] = "sunday";
    char str2[] = "saturday";
 
    printf("%d\n", EditDistance(str1, str2, strlen(str1), strlen(str2)));
 
    return 0;
}
