#ifndef _BINOMIAL_HEAP_H
#define _BINOMIAL_HEAP_H

struct node;
typedef struct node Node;
struct node{
        Node* parent;
        Node* child;
        Node* sibling;
        int value;
        int degree;
};

class BinomialHeap{
    private:
        Node *H;
    public:
        BinomialHeap();
        //~BinomialHeap();
        Node* CreateNode(int k);
        void Insert(int k);
        Node* Initialise();
        int GetMin();
        void ExtractMin();
        void Delete(int val);
        void DecreaseKey(int k, int newVal); 
        void Union(Node *H1);
        void MergeTree(Node *first, Node *second);
        void Merge(Node *H2);
};
#endif

