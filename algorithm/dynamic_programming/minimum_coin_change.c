#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int MinChange(int *coins, int V, int m) {
    int table[V+1];

    for (int i = 0; i < V+1; i++) table[i] = INT_MAX;

    table[0] = 0;

    for (int i = 1; i < V+1; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub = table[i-coins[j]];
                if (sub != INT_MAX && sub+1 <= table[i])
                   table[i] = sub+1; 
            }
        }
    }

    return table[V];
}

// Driver program to test above function
int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    printf("Minimum coins required is %d\n", MinChange(coins, V, m));
    return 0;
}
