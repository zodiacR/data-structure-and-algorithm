#include <iostream>
#include <climits>
#include "binomial_heap.h"
using namespace std;


BinomialHeap::BinomialHeap(){
    H = Initialise();
}

Node* BinomialHeap::Initialise(){
    return NULL;
}

Node* BinomialHeap::CreateNode(int k){
    Node *n = new Node;
    n->parent = n->child = n->sibling = NULL;
    n->value = k;
    n->degree = 0;

    return n;
}

void BinomialHeap::Insert(int k){
    Node *n = CreateNode(k);
    Union(n);
}

int BinomialHeap::GetMin(){
    Node* h = H;
    int min = INT_MAX;
    while (h){
        if (h->value < min) min = h->value;
        h = h->sibling;
    }
}

void ExtractMin();

void Delete(int val);

void DecreaseKey(int k, int newVal); 

void BinomialHeap::Union(Node *H1){

    Merge(H1);
    Node* prev = NULL;    
    Node* x = H;
    Node* next = x->sibling; 

    while (next) {
        if (x->degree != next->degree || 
                next->sibling && x->degree == next->sibling->degree){
            prev = x;
            x = next;
        }else if (x->degree <= next->degree){
            x->sibling = next->sibling;         
            MergeTree(next, x);
        }else{
            if (!prev) H = next;
            else prev->sibling = x->sibling; 
            MergeTree(x, next);
            x = next;
        }

        next = next->sibling;
    }
}

void BinomialHeap::MergeTree(Node *first, Node *second){
    first->parent = second;
    first->sibling = second->child;
    second->child = first;
    second->degree += 1;
}

void BinomialHeap::Merge(Node *H2){
    Node *head, *current; 
    Node *head1 = H;
    Node *head2 = H2;

    if (!H){
        H = head2;
        return;
    }
    if (!H2) return;

    if (H->degree < H2->degree){
        head = current = head1;
        head1 = head1->sibling;
    } else{
        head = current = H2;
        head2 = head2->sibling;
    }

    while (head1 && head2){
        if (head1 < head2){
            current->sibling = head1; 
            current = head1;
            head1 = head1->sibling;
        } else{
            current->sibling = head2;
            current = head2;
            head2 = head2->sibling;
        }
    }

    while (head1){
        current->sibling = head1; 
        current = head1;
        head1 = head1->sibling;
    }
    while (head2){
        current->sibling = head2;
        current = head2;
        head2 = head2->sibling;
    }

    H = head;
}
