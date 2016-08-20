#include <stdlib.h>
#include <stdio.h>

typedef int Element;
struct node {
    Element data;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

int SearchIndex(Element arr[], int strt, int end, Element value);
Node CreateNode(Element value);
Node BuildeTree(Element pre[], Element in[], int inStrt, int inEnd);

void Preorder(Node t) {
    if (!t) return;

    printf("%d ", t->data);
    Preorder(t->left);
    Preorder(t->right);
}

void Inorder(Node t) {
    if (!t) return;

    Inorder(t->left);
    printf("%d ", t->data);
    Inorder(t->right);
}

void Postorder(Node t) {
    if (!t) return;

    Postorder(t->left);
    Postorder(t->right);
    printf("%d ", t->data);
}


void Dispose(Node n){
    if (!n) return;

    Dispose(n->left);
    Dispose(n->right);
    free(n); 
}

void DeTree(Node* t){
    Dispose(*t);

    *t = NULL;
}


int main() {
    int in[] = {10, 15, 20, 23, 25, 30, 35, 39, 42};
    int pre[] = {30, 20, 10, 15, 25, 23, 39, 35, 42};
    int start = 0;
    int end = sizeof(in)/sizeof(in[0]) - 1;

    Node t = BuildeTree(pre, in, start, end);

    printf("Preorder: ");
    Preorder(t);
    printf("\nInorder: ");
    Inorder(t);
    printf("\n");
    printf("Postorder: ");
    Postorder(t);
    printf("\n");

    DeTree(&t);
    return 0;
}

int SearchIndex(Element arr[], int strt, int end, Element value){
    for (int i = strt; i <= end; i++){
        if(arr[i] == value) return i;
    }
}

Node CreateNode(Element value){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = value;
    n->left = n->right = NULL;

    return n;
}

Node BuildeTree(Element pre[], Element in[], int inStrt, int inEnd){
    static int preIndex = 0;

    if (inStrt > inEnd) return NULL;

    Node tn = CreateNode(pre[preIndex++]);

    if (inStrt == inEnd) return tn;

    int inIndex = SearchIndex(in, inStrt, inEnd, tn->data);

    tn->left = BuildeTree(pre, in, inStrt, inIndex-1);
    tn->right = BuildeTree(pre, in, inIndex+1, inEnd);

    return tn;
}

