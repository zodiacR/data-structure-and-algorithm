#include <stdio.h>
#include <stdlib.h>

#define Max(a,b) a>b?a:b

int FindMaxSum(int *arr, int n) {
    int excl = 0;
    int incl = arr[0];

    for (int i = 1; i < n; i++) {
        int excl_new = incl > excl ? incl:excl;
        incl = excl + arr[i];
        excl = excl_new;
    }

    return incl > excl ? incl:excl;
}

int FindMaxSum2(int *arr, int n) {
    int *max = (int*)malloc(sizeof(int)*n);

    max[0] = arr[0];
    max[1] = Max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        max[i] = Max(max[i-1], arr[i]+max[i-2]);
    }

    int max_sum = max[n-1];
    free(max);

    return max_sum;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {5, 5, 10, 50, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d \n", FindMaxSum(arr, n));
    printf("%d \n", FindMaxSum2(arr, n));
    return 0;
}
