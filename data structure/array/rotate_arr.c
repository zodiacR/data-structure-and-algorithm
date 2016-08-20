#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b){
    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

void Rotate(int *arr, int n, int d) {
    for (int i = 0; i < GCD(n, d); i++) {
        int j = i;
        int tmp = arr[i]; 

        while (1) {
            int k = j + d;
            if (k >= n) k -= n;
            if (k == i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = tmp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
   for (int i = 1; i < 8; i++) {
       int arr[] = {1, 2, 3, 4, 5, 6, 7};
       Rotate(arr, 7, i);
       printArray(arr, 7);
       printf("--------------------------\n");
   }
   return 0;
}
