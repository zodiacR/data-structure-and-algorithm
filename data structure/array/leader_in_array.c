#include <stdio.h>
#include <stdlib.h>

void Leaders(int *arr, int n) {
    int leader = arr[n-1];
    printf("%d ", arr[n-1]);

    for (int i = n-2; i >= 0; i--) {
        if (leader < arr[i]) {
            printf("%d ", arr[i]);
            leader = arr[i];
        }
    }
    printf("\n");
}

/* Driver program to test above function*/
int main()
{
    int arr[] = {16, 17, 4, 9, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Leaders(arr, n);
    return 0;
}    
