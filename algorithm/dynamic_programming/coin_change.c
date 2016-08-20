#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int *S, int m, int n){
    int table[n+1];

    memset(table, 0, sizeof(table));

    table[0] = 1;

    for(int i = 0; i < m; i++)
        for (int j = S[i]; j <= n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

int main()
{
    int arr[] = {2, 5, 3, 6};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 10;
    printf(" %d \n", count(arr, m, n));
    return 0;
}
