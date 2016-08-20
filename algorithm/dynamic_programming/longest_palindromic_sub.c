#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {  return a>b? a:b;}

int LPS(char *s, int n) {
    int lps[n][n];

    for (int i = 0; i < n; i++) lps[i][i] = 1;

    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n-cl+1; i++) {
            int j = i + cl - 1;
            if (s[i] == s[j] && j-i == 1) lps[i][j] = 2;
            else if (s[i] == s[j]) lps[i][j] = lps[i+1][j-1] + 2;
            else lps[i][j] = max(lps[i][j-1], lps[i+1][j]);
        }
    }

    return lps[0][n-1];
}

/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d\n", LPS(seq, n));
    return 0;
}
