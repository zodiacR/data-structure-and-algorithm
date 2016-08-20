#include <stdio.h>
#include <stdlib.h>

struct heap;
typedef struct heap MaxHeap;

struct heap{
    int size;
    int *arr;
};

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(MaxHeap* heap, int idx){
    int largest = idx;
    int lchild = (idx<<1) + 1;
    int rchild = (idx + 1) << 1;

    if (lchild < heap->size &&
            heap->arr[lchild] > heap->arr[largest])
        largest = lchild;
    if (rchild < heap->size &&
            heap->arr[rchild] > heap->arr[largest])
        largest = rchild;

    if (largest != idx){
        swap(&heap->arr[largest], &heap->arr[idx]);
        maxHeapify(heap, largest);
    }
}

MaxHeap* CreateHeap(int *arr, int size){
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(struct heap));
    heap->size = size;
    heap->arr = arr;

    for (int i = (size-2)/2; i >= 0; i--){
        maxHeapify(heap, i);
    }

    return heap;
}

void heapSort(int *arr, int size){
    MaxHeap* heap = CreateHeap(arr, size);

    while (heap->size > 1){
        swap(&heap->arr[0], &heap->arr[heap->size-1]);
        --heap->size;

        maxHeapify(heap, 0);
    }
}

// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, size);
 
    heapSort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    printf("\n");
    return 0;
}
