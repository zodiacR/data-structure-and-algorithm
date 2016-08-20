#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max (int a, int b) { return a>b?a:b;}

int eggdrop(int n, int k) {
    int eggFloor[n+1][k+1];


    // k == 0 || k == 1;
    for (int i = 0; i <= n; i++) {
        eggFloor[i][0] = 0;
        eggFloor[i][1] = 1;
    }
    // n == 1;
    for (int i = 0; i <= k; i++) eggFloor[1][i] = i;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++){
            int res;
            eggFloor[i][j] = INT_MAX;
            for (int m = 1; m <= j; m++) {
                res = 1 + max(eggFloor[i-1][m-1], eggFloor[i][j-m]);
                if (res < eggFloor[i][j]) eggFloor[i][j] = res;
            }
        }
    }

    return eggFloor[n][k];
}


/* Driver program to test to pront printDups*/
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf ("\nMinimum number of trials in worst case with %d eggs and "
			"%d floors is %d \n", n, k, eggdrop(n, k));
	return 0;
}
