#include <stdio.h>
#include <stdlib.h>

int merge(int *arr, int *tmp, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;

    int inversion = 0;

    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
            k++;
        } else {
            tmp[k] = arr[j];
            j++;
            k++;
            inversion += mid-i+1;
        }
    }

    while (i <= mid){
        tmp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right){
        tmp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++) arr[i] = tmp[i];

    return inversion;
}

int MergeSort(int *arr, int *tmp, int left, int right){
    int inversion = 0;
    if (left < right) {
        int mid = (left + right)/2;
        inversion += MergeSort(arr, tmp, left, mid);
        inversion += MergeSort(arr, tmp, mid+1, right);
        inversion += merge(arr, tmp, left, mid, right);

    }
    return inversion;
}

/* Driver progra to test above functions */
int main()
{
  /*int arr[] = {1, 20, 6, 4, 5};*/
  int arr[] = {0, 1, 2, 9, 6, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int tmp[n];
  printf(" Number of inversions are %d \n", MergeSort(arr, tmp, 0, n-1));
  return 0;
}
