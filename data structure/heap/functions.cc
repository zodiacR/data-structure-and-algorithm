#include <iostream>
#include <climits>
#include "heap.h"
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}


MinHeap::MinHeap(int cap){
    capacity = cap;
    heap_size = 0;
    harr = new int[cap];
}

MinHeap::~MinHeap(){
    delete [] harr;
}

void MinHeap::InsertKey(int key){
    if (capacity == heap_size){
        cout << "\nOverflow: Couldn't insert key\n";    
        return;
    }

    // insert the key to the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = key;

    // fix the min heap property if it is violated
    while (i !=0 && harr[parent(i)] > harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i); 
    }
}

void MinHeap::DeleteKey(int i){
    DecreaseKey(i, INT_MIN);
    ExtractMin(); 
}

int MinHeap::GetMin() {
    if (heap_size <= 0)
        return INT_MIN;
    return harr[0];
}

void MinHeap::DecreaseKey(int i, int new_val){
    // decrease key
    harr[i] = new_val;
    // fix the min heap property if it is violated
    while (i !=0 && harr[parent(i)] > harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i); 
    }
}

int MinHeap::ExtractMin(){
    if (heap_size <= 0) return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}
void MinHeap::MinHeapify(int index){
    int l = left(index); 
    int r = right(index); 
    int smallest = index;

    if (l < heap_size && harr[index] > harr[l])
        smallest = l;
    if (r < heap_size && harr[smallest] > harr[r])
        smallest = r;
    if (smallest != index){
        swap(harr[index], harr[smallest]);
        MinHeapify(smallest);
    }
}
