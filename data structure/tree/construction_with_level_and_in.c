#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "tree.h"


int SearchIndex(Element *in, int n, Element value);
Node* CreateNode(Element value);
Node* BuildeTree(Element level[], Element in[], int *vis, int n);

int main(){

    Node *t = NULL;
    Element level[] = {4, 3, 5, 1, 2, 6, 7 ,8};
    Element in[] = {1, 3, 2, 4, 5, 7 , 6, 8};
    int n = sizeof(level) / sizeof(level[0]);
    int vis[n];

    for(int i = 0; i < n; i++) vis[i] = 0;
    t = BuildeTree(level, in, vis, n);
    
    printf("Preorder: ");
    Preorder(t);
    printf("\nInorder: ");
    Inorder(t);
    printf("\nPostorder: ");
    Postorder(t);
    printf("\n");
    printf("BFS: ");
    BFS(t);
    DeTree(&t);
}

int SearchIndex(Element *in, int n, Element value){
    for(int i = 0; i < n; i++)
        if (in[i] == value) return i;
    return -1;
}

Node* CreateNode(Element value){
    Node* n = (Node*)malloc(sizeof(struct node));
    n->data = value;
    n->right = n->left = NULL;

    return n;
}

Node* BuildeTree(Element level[], Element in[], int *vis, int n){
    int i = 0;
    Node *t = CreateNode(level[i++]);        
    Queue* q = CreateQueue(30); 
    Enqueue(q, t);
    vis[SearchIndex(in, n, t->data)] = 1;

    while (!IsEmpty(q)){
        Node* tmp = Dequeue(q);
        int pos = SearchIndex(in, n, tmp->data); 

        if (pos > 0 && vis[pos-1] != 1){
            tmp->left = CreateNode(level[i++]);
            Enqueue(q, tmp->left);
            vis[SearchIndex(in, n, level[i-1])] = 1;
        }
        if (pos < n-1 && vis[pos+1] != 1) {
            tmp->right = CreateNode(level[i++]);
            Enqueue(q, tmp->right);
            vis[SearchIndex(in, n, level[i-1])] = 1;
        }
    }

    q = DisposeQueue(q);

    return t;
}
