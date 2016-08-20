#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    Node *t = NULL;
    int arr[] = {6,2,1,4,3,5,7,8,12,10,9,11,13};
    int height = 0;
    int n = sizeof(arr) / sizeof(*arr);

    for (int i = 0; i < n; i++){
        printf("Insert %dth: %d\n", i, arr[i]);
        Insert(&t, arr[i]); 
    }

    printf("Preorder: ");
    Preorder(t);
    printf("\n");

    printf("\nDiameter of the given binary tree is %d\n", DiameterOpt(t, &height));
    DeTree(&t);

    return 0;
}
void Insert(Tree t, Element e){
    if (!(*t)) {
        CreateTree(t, e);
        return;
    }

    Node* temp = *t;
    Node* parent = *t;
    int flag = 0;
    
    while (temp) {
        parent = temp;
        if (e >= temp->data) {
            temp = temp->right;
            flag = 1;
        }
        else {
            temp = temp->left;
            flag = 0;
        }
    }

    Node* n = (Node*)malloc(sizeof(Node));
    n->data = e;
    n->left = n->right = NULL;

    if (!flag) parent->left = n;
    else parent->right = n;
}

void CreateTree(Tree t, Element e){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->right = node->left = NULL;

    *t = node;
}

void DeTree(Tree t){
    Dispose(*t);

    *t = NULL;
}

void Dispose(Node* n){
    if (!n) return;

    Dispose(n->left);
    Dispose(n->right);
    free(n); 
}

int DiameterOpt(Node* n, int *height){
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;


    if(n == NULL) {
        *height = 0;
        return 0;
    }

    ldiameter = DiameterOpt(n->left, &lh);
    rdiameter = DiameterOpt(n->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh+rh+1, max(ldiameter, rdiameter));
}

void Preorder(Node* n){
    if (!n) return;

    printf("%d ", n->data);
    Preorder(n->left);
    Preorder(n->right);
}
int max(int a, int b) {
    return a>b? a:b;
}
