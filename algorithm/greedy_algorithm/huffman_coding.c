#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100

typedef struct node{
    char data;
    int freq;
    struct node *left;
    struct node *right;
}Node;

typedef struct minheap{
    int size;
    int capacity;
    Node **harr;
}MinHeap;

MinHeap* CreateMinHeap(int size){
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->size = 0;
    h->capacity = size;
    h->harr = (Node**)malloc(sizeof(Node*) * size);

    return h;
}

void swap(Node** a, Node** b){
    Node* tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void MinHeapify(MinHeap *h, int idx){
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    int smallest = idx;

    if (l < h->size && h->harr[l]->freq < h->harr[smallest]->freq)
        smallest = l;
    if (r < h->size && h->harr[r]->freq < h->harr[smallest]->freq)
        smallest = r;

    if (idx != smallest){
        swap(&(h->harr[smallest]), &(h->harr[idx]));
        MinHeapify(h, smallest);
    }
}

void BuildMinHeap(MinHeap *h){
    int i = (h->size-2) / 2;

    while (i){
        MinHeapify(h, i);
        i--; 
    }
}

Node* ExtractMin(MinHeap* h){
    if (h->size == 0) return NULL;
    if (h->size == 1) {
        h->size--;
        return h->harr[0];
    }

    Node* tmp = h->harr[0];
    h->harr[0] = h->harr[h->size-1];
    h->size--;
    MinHeapify(h, 0);

    return tmp;
}

int parent(int i){
    return (i-1)/2;
}

void Insert(MinHeap* h, Node* n){
    h->size++;
    int i = h->size-1;
    h->harr[i] = n;

    while (i && h->harr[parent(i)]->freq > h->harr[i]->freq) {
        swap(&(h->harr[i]), &(h->harr[parent(i)]));
        i = parent(i);  
    }
}

Node* CreateNode(char data, int freq){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->freq = freq;
    n->left = n->right = NULL;

    return n;
}

int IsSizeOne(MinHeap* h) {
    return (h->size == 1);
}

MinHeap* BuildHuffmanTree(char* chars, int* freq, int n){
    MinHeap* h = CreateMinHeap(n);
    
    for (int i = 0; i < n; i++){
        Node* tmp = CreateNode(chars[i], freq[i]);
        h->harr[i] = tmp;
    }

    h->size = n;
    BuildMinHeap(h);

    /*for (int i = 0; i < n; i++){*/
        /*printf("%c: %d\n", h->harr[i]->data,*/
                           /*h->harr[i]->freq);*/
    /*}*/

    while(!IsSizeOne(h)){
        Node* left = ExtractMin(h);
        Node* right = ExtractMin(h);
        /*printf("%c: %d\n", left->data, left->freq);*/
        /*printf("%c: %d\n", right->data, right->freq);*/

        Node* root = CreateNode('$', left->freq+right->freq);

        root->left = left;
        root->right = right;
        Insert(h, root);
    }

    return h;
}

void Dispose(MinHeap** h){
    free((*h)->harr); 
    free(*h);
}

int IsLeaf(Node *n){
    return (!(n->left) && !(n->right));
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
 

void printCodes(Node* root, int* arr, int top){

    if (root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if (root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if (IsLeaf(root)){
        printf("%c: ", root->data);
        printArr(arr, top);
    }
    
}

void Inorder(Node* root){
    if (root){
        Inorder(root->left);
        printf("%c: %d\n", root->data, root->freq);
        Inorder(root->right);
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
   //  Construct Huffman Tree
    MinHeap* h = BuildHuffmanTree(data, freq, size);
 
   // Print Huffman codes using the Huffman tree built above
    int arr[MAX_TREE_HT], top = 0;
    Node* root = ExtractMin(h);
    printCodes(root, arr, top);
    Dispose(&h);
}
 
// Driver program to test above functions
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}
