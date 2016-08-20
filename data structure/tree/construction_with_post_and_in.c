#include <stdio.h>
#include <stdlib.h>

typedef int Element;
struct node{
    Element data;
    struct node* left;
    struct node* right;
};

int postIndex;
typedef struct node* Node;

int SearchIndex(Element arr[], int strt, int end, Element value);
Node CreateNode(Element value);
Node BuildeTree(Element post[], Element in[], int inStrt, int inEnd);

void Postorder(Node t) {
    if (!t) return;

    Postorder(t->left);
    Postorder(t->right);
    printf("%d ", t->data);
}

void Inorder(Node t) {
    if (!t) return;

    Inorder(t->left);
    printf("%d ", t->data);
    Inorder(t->right);
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
    int in[] = {1, 3, 2, 4, 5, 7, 6, 8};
    int post[] = {1, 2, 3, 5, 7, 8, 6, 4};
    int start = 0;
    int end = sizeof(in)/sizeof(in[0]) - 1;
    postIndex = end;

    Node t = BuildeTree(post, in, start, end);

    printf("Postorder: ");
    Postorder(t);
    printf("\nInorder: ");
    Inorder(t);
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

Node BuildeTree(Element post[], Element in[], int inStrt, int inEnd){

    if(inStrt > inEnd) return NULL;

    Node n = CreateNode(post[postIndex--]);

    if (inStrt == inEnd) return n;

    int inIndex = SearchIndex(in, inStrt, inEnd, n->data);
    n->right = BuildeTree(post, in, inIndex+1, inEnd);
    n->left = BuildeTree(post, in, inStrt, inIndex-1);

    return n;
}
