#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct adjlistnode{
    int dest;
    int weight;
    struct adjlistnode* next;
}AdjListNode;

typedef struct adjlist {
    AdjListNode *head;
}AdjList;

typedef struct graph {
    int V;
    AdjList *arr;
}Graph;

AdjListNode* NewNode(int dest, int weight) {
    AdjListNode* n = (AdjListNode*)malloc(sizeof(AdjListNode));
    n->dest = dest;
    n->weight = weight;
    n->next = NULL;

    return n;
}

Graph* CreateGraph(int V){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->arr = (AdjList*)malloc(V * sizeof(AdjList));

    for (int i = 0 ; i < V; i++){
        g->arr[i].head = NULL; 
    }

    return g;
}

void AddEdge(Graph* g, int src, int dest, int weight){
    AdjListNode* node = NewNode(dest, weight);
    node->next = g->arr[src].head;
    g->arr[src].head = node;

    node = NewNode(src, weight);
    node->next = g->arr[dest].head;
    g->arr[dest].head = node;
}

typedef struct minheapnode{
    int v;
    int key;
}MinHeapNode;

typedef struct minheap{
    int capacity;
    int size;
    int *pos;
    MinHeapNode **heap;
}MinHeap;

MinHeap* CreateMinHeap(int size){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = size;
    heap->size = 0;
    heap->heap = (MinHeapNode**)malloc(sizeof(MinHeapNode*) * size);
    heap->pos = (int*)malloc(sizeof(int) * size);

    return heap;
}

MinHeapNode* CreateMinHeapNode(int v, int key){
    MinHeapNode* n = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    n->v = v;
    n->key = key;

    return n;
}

void swap(MinHeapNode** a, MinHeapNode** b){
    MinHeapNode* tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void MinHeapify(MinHeap* heap, int idx){
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;

    if (l < heap->size &&
            heap->heap[l]->key < heap->heap[smallest]->key)
        smallest = l;
    if (r < heap->size &&
            heap->heap[r]->key < heap->heap[smallest]->key)
        smallest = r;

    if (smallest != idx){
        heap->pos[heap->heap[smallest]->v] = idx; 
        heap->pos[heap->heap[idx]->v] = smallest; 

        swap(&(heap->heap[smallest]), &(heap->heap[idx]));
        MinHeapify(heap, smallest);
    }
}

int IsEmpty(MinHeap* h) {
    return h->size == 0;
}

MinHeapNode* Extract(MinHeap* heap){
    if (IsEmpty(heap)) return NULL;

    MinHeapNode* root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size-1];

    heap->pos[root->v] = heap->size - 1;
    heap->pos[heap->heap[0]->v] = 0;

    --heap->size;
    MinHeapify(heap, 0);

    return root;
}

int parent(int i) {
    return (i-1)/2;
}

void Decrease(MinHeap* heap, int v, int key){
    int i = heap->pos[v]; 
    heap->heap[i]->key = key;

    while (i && heap->heap[i]->key < heap->heap[parent(i)]->key){
        heap->pos[heap->heap[i]->v] = parent(i); 
        heap->pos[heap->heap[parent(i)]->v] = i; 
        swap(&(heap->heap[i]), &(heap->heap[parent(i)]));
        i = parent(i);
    }
}

int IsInMinHeap(MinHeap* h, int v){
    if (h->pos[v] < h->size)
        return 1;
    else return 0;
}

void printArr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}

void PrimMST(Graph* g){

    int parent[g->V];
    MinHeap* heap = CreateMinHeap(g->V);

    for (int i = 0; i < g->V; i++){
        heap->pos[i] = i;
        heap->heap[i] = CreateMinHeapNode(i, INT_MAX);
    }

    heap->size = g->V;

    Decrease(heap, 0, 0);
    parent[0] = -1;

    while(!IsEmpty(heap)){
        MinHeapNode* u = Extract(heap); 

        AdjListNode *n = g->arr[u->v].head;
        while(n){
            if (IsInMinHeap(heap, n->dest) &&
                    n->weight < heap->heap[heap->pos[n->dest]]->key){
                parent[n->dest] = u->v;
                Decrease(heap, n->dest, n->weight);
            }
            n = n->next;
        }
    }

    printArr(parent, g->V);
}

// Driver program to test above functions
int main()
{
    // Let us create the graph given in above fugure
    int V = 9;
    Graph* graph = CreateGraph(V);
    AddEdge(graph, 0, 1, 4);
    AddEdge(graph, 0, 7, 8);
    AddEdge(graph, 1, 2, 8);
    AddEdge(graph, 1, 7, 11);
    AddEdge(graph, 2, 3, 7);
    AddEdge(graph, 2, 8, 2);
    AddEdge(graph, 2, 5, 4);
    AddEdge(graph, 3, 4, 9);
    AddEdge(graph, 3, 5, 14);
    AddEdge(graph, 4, 5, 10);
    AddEdge(graph, 5, 6, 2);
    AddEdge(graph, 6, 7, 1);
    AddEdge(graph, 6, 8, 6);
    AddEdge(graph, 7, 8, 7);
 
    PrimMST(graph);
 
    return 0;
}
