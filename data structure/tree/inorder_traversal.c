#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

void InorderWithStack(Node* n){
    int done = 1;
    Node *tmp = n;
    Stack s = NULL;
    while (done) {
        while (tmp) {
            push(&s, tmp);
            tmp = tmp->left;
        }
        if (!IsEmptyStack(s)) {
            Node* parent = pop(&s); 
            printf("%d ", parent->data);
            tmp = parent->right;
        }
        else done = 0;
    }
}

void PreorderWithStack(Node* n){
    int done = 1;
    Node *tmp = n;
    Stack s = NULL;
    while (done) {
        while (tmp) {
            push(&s, tmp);
            printf("%d ", tmp->data);
            tmp = tmp->left;
        }
        if (!IsEmptyStack(s)) {
            Node* parent = pop(&s); 
            tmp = parent->right;
        }
        else done = 0;
    }
}

int main() {

    Node *t = NULL;
    int arr[] = {4,3,1,7,5,8};
    int n = sizeof(arr) / sizeof(*arr);

    for (int i = 0; i < n; i++){
        printf("Insert %d\n", arr[i]);
        Insert(&t, arr[i]); 
    }

    printf("Preorder: ");
    Preorder(t);
    printf("\n");
    printf("Inorder: ");
    Inorder(t);
    printf("\n");
    printf("Postorder: ");
    Postorder(t);
    printf("\n");
    printf("Preorder: ");
    PreorderWithStack(t);
    printf("\n");
    printf("Inorder: ");
    InorderWithStack(t);
    printf("\n");
    DeTree(&t);
}

