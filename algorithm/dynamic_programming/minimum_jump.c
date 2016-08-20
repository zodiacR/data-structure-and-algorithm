#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) { return a<b?a:b; }

int MinJumps(int *arr, int n) {
    int jumps[n];
    int path[n];

    if (n == 0 || arr[0] == 0) return INT_MAX;

    for (int i = 0; i < n; i++)
        jumps[i] = INT_MAX;

    jumps[0] = 0;
    path[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i <= j+arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j]+1);
                path[i] = j;
                break;
            }
        }
    }

    int k = n-1;
    printf("%d ", n-1);
    while (path[k]) {
        printf("%d ", path[k]);
        k = path[k];
    }

    return jumps[n-1];
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("\nMinimum number of jumps to reach end is %d \n", MinJumps(arr,size));
    return 0;
}
