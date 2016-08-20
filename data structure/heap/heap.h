#ifndef _HEAP_H
#define _HEAP_H
class MinHeap{
    private:
        int *harr;
        unsigned capacity;
        unsigned heap_size;

    public:
        MinHeap(int capacity);
        ~MinHeap();
        void InsertKey(int i);
        void DeleteKey(int i);
        int GetMin();
        void DecreaseKey(int i, int new_val);
        int ExtractMin();
        void MinHeapify(int index);
        int parent(int index) { return (index-1)/2; }
        int left(int index) { return (2*index + 1); }
        int right(int index) { return (2*index + 2); }
};

#endif
