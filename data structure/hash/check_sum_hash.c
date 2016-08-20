#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void PrintPairs(int *arr, int n, int sum){
    int binMap[MAX] = {0};
    int tmp;

    for (int i = 0; i < n; i++){
        tmp = sum - arr[i];
        if (tmp > 0 && binMap[tmp]){
            printf("Pair with given sum %d is (%d, %d) \n",
                    sum, arr[i], tmp);
        }
        binMap[arr[i]] = 1;
    }
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    PrintPairs(A, arr_size, n);
 
    return 0;
}
