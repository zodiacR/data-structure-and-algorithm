#include <iostream>
using namespace std;

class MinHeap{
    private:
        int heap_size;
        int *harr;
    public:
        MinHeap(int *arr, int size);
        void MinHeapify(int idx);
        int ExtractMin();
        int ReplaceMin(int x);
};

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

MinHeap::MinHeap(int *arr, int size){
    harr = arr;
    heap_size = size;
    int i = (heap_size-1)/2;
    while (i>=0){
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int idx){
    int smallest = idx;
    int lchild = (idx<<1) + 1;
    int rchild = (idx+1) << 1;

    if (lchild < heap_size && harr[smallest] > harr[lchild])
        smallest = lchild;
    if (rchild < heap_size && harr[smallest] > harr[rchild])
        smallest = rchild;

    if (smallest != idx){
        swap(harr[smallest], harr[idx]);
        MinHeapify(smallest);
    }
}

int MinHeap::ReplaceMin(int x){
    int root = harr[0]; 
    harr[0] = x;

    if (root < x){
        MinHeapify(0);
    }

    return root;
}

int MinHeap::ExtractMin(){
    int root = harr[0];
    if (heap_size > 1){
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
    }

    return root;
}

void sortK(int *arr, int n, int k){
    int *harr = new int[k+1];
    for (int i = 0; i <= k && i < n; i++)
        harr[i] = arr[i];

    MinHeap h(harr, k+1);

    for (int i = k+1, ti = 0; ti < n; i++, ti++){
        if (i < n){
            arr[ti] = h.ReplaceMin(arr[i]);
        } else {
            arr[ti] = h.ExtractMin();
        }
    }

    delete [] harr;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       cout << arr[i] << " ";
   cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout << "Following is original arry" << endl;
    //printArray(arr, n);
    sortK(arr, n, k);
 
    cout << "Following is sorted array\n";
    printArray (arr, n);
 
    return 0;
}
