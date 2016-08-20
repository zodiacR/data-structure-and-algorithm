#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

Node LCA(Node root, Element a, Element b){
    int diff = (a-root->data) * (b-root->data);
    while(root && diff > 0) {
        root = root->data - a > 0 ? root->left: root->right;  
        if (root)
            diff = (a-root->data) * (b-root->data);
    }

    return root;
}

int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node root = NULL;
    root        = Insertion(root,20);
    root              = Insertion(root,8);
    root              = Insertion(root,22);
    root         = Insertion(root,4);
    root        = Insertion(root,12);
    root  = Insertion(root,10);
    root = Insertion(root,14);
 
    Inorder(root);
    printf("\n");

    Element n1 = 10, n2 = 14;
    Node t = LCA(root, n1, n2);
    if (t)
        printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    else
        printf("LCA of %d and %d is None \n", n1, n2);

 
    n1 = 14, n2 = 8;
    t = LCA(root, n1, n2);
    if (t)
        printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    else
        printf("LCA of %d and %d is None \n", n1, n2);
 
    n1 = 10, n2 = 22;
    t = LCA(root, n1, n2);
    if (t)
        printf("LCA of %d and %d is %d \n", n1, n2, t->data);
    else
        printf("LCA of %d and %d is None \n", n1, n2);

    return 0;
}
