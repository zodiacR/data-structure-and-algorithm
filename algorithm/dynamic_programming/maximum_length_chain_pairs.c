#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    int first;
    int second;
}Pair;

int MAX(int a, int b) {
    return a>b?a:b;
}

int MaxChainLength(Pair *pairs, int n) {
    int mcl[n];

    for (int i = 0; i < n; i++) {
        mcl[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].first && mcl[i] < mcl[j]+1)
                mcl[i] = mcl[j] + 1;
        }
    }

    int max = mcl[0];

    for (int i = 1; i < n; i++) {
        max = MAX(max, mcl[i]);
    }

    return max;
}

/* Driver program to test above function */
int main()
{
    /*struct pair arr[] = { {5, 24}, {15, 25},*/
                          /*{27, 40}, {50, 60}};*/
    Pair arr[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           MaxChainLength( arr, n ));
    return 0;
}
