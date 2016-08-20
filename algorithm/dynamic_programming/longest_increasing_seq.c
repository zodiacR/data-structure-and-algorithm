#include <stdio.h>
#include <stdlib.h>

int LIS(int *arr, int n){
    int lis[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        prev[i] = i;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
                prev[i] = j;
                /*printf("%d %d %d\n", i, j, prev[i]);*/
            }
        }
    }

    int max = lis[0];
    int idx = 0;
    for (int i = 1; i < n; i++){
        if (max < lis[i]) {
            max = lis[i];
            idx = i;
        }
    }
    
    printf("(%d %d),", arr[idx], idx);
    while (prev[idx] != idx) {
        printf("(%d %d),", arr[prev[idx]], prev[idx]);
        idx = prev[idx];
    }
    printf("\n");

    return max;
}

int main()
{
  /*int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };*/
  int arr[] = {34, 7, 27, 62, 90, 88, 80, 22, 13, 40};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", LIS(arr, n));
  return 0;
}
