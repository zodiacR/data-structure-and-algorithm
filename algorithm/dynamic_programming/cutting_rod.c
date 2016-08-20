#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a>b?a:b;
}

int MaxCutting(int *arr, int n) {
    int values[n+1];

    values[0] = 0;

    for (int i = 1; i <= n; i++) {
        values[i] = INT_MIN;
        for (int j = 0; j < i; j++) {
            values[i] = max(values[i], values[j]+ arr[i-1-j]);
        }
    }

    return values[n];
}
/* Driver program to test above functions */
int main()
{
    int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", MaxCutting(arr, size));
    return 0;
}
