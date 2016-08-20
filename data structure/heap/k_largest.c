#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N(arr) sizeof(arr)/sizeof(arr[0])

struct heap;
typedef struct heap MaxHeap;

struct heap{
    int size;
    int *arr;
};

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(MaxHeap* heap, int idx){
    int largest = idx;
    int lchild = (idx<<1) + 1;
    int rchild = (idx + 1) << 1;

    if (lchild < heap->size &&
            heap->arr[largest] < heap->arr[lchild])
        largest = lchild;
    if (rchild < heap->size &&
            heap->arr[largest] < heap->arr[rchild])
        largest = rchild;

    if (largest != idx){
        swap(&heap->arr[largest], &heap->arr[idx]);
        maxHeapify(heap, largest);
    }
}

MaxHeap* CreateHeap(int *arr, int size){
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(struct heap));
    heap->arr = (int*)malloc(sizeof(size));
    for (int i = 0; i < size; i++)
        heap->arr[i] = arr[i];

    heap->size = size;

    for (int i = (size-2)/2; i >= 0; i--)
        maxHeapify(heap, i);

    return heap;
}

void DeleteHeap(MaxHeap* heap){
    free(heap->arr);
    free(heap);
}

int ExtractMax(MaxHeap *heap){
    if (heap->size <= 0) INT_MAX; 
    if (heap->size == 1) return heap->arr[0];

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    --heap->size;
    maxHeapify(heap, 0);

    return root;
}

void Selection(int* arr, int k, int n){
    for (int i = 0; i < k; i++){
        int max = i;
        for (int j = i+1; j < n; j++){
            if (arr[max] < arr[j]) max = j;
        }
        if (max != i)
            swap(&arr[i], &arr[max]);
        printf("%dth: %d\n", i+1, arr[i]);
    }
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = N(arr);
    int k = 3;
    MaxHeap* heap = CreateHeap(arr, n);

    for (int i = 0; i < k; i++)
        printf("%dth: %d\n", i+1, ExtractMax(heap));

    Selection(arr, k , n);

    return 0;
}
