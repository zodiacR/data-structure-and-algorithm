#include <stdio.h>
#include <stdlib.h>
#define N(arr) sizeof(arr) / sizeof(arr[0])


int cmp(const void *a, const void* b){
    return *(int*)a - *(int*)b;
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++){
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(int *arr, int low, int high){
    if (low < high){
        int mid = partition(arr, low, high);
        quicksort(arr, low, mid-1);
        quicksort(arr, mid+1, high);
    }
}

void Print(int *arr, int n){
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\n");
}

int main(){
    int A[] = {1, 4, 45, 6, 10, -8};
    int n = N(A);

    Print(A, n);
    /*quicksort(A, 0, n-1);*/
    qsort(A, n, sizeof(int), cmp);
    Print(A, n);
}
