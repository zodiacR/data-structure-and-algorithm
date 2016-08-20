#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

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
    printf("\nInorder: ");
    Inorder(t);
    printf("\nPostorder: ");
    Postorder(t);
    printf("\n");
    printf("BFS: ");
    BFS(t);
    DeTree(&t);

    return 0;
}

