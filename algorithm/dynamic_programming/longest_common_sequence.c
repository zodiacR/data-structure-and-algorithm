#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a>b) ? a:b; 
}

int LCS(char *s, char *k, int n, int m){
    int lcs[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) lcs[i][j] = 0;
            else if (s[i-1] == k[j-1]) lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }

    return lcs[n][m];
}

/* Driver program to test above function */
int main()
{
  char X[] = "AGGTABB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", LCS( X, Y, m, n ) );
 
  return 0;
}
