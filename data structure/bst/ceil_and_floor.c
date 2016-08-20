#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#define MAX 32765

Element Ceil(Node root, Element key){
    if (!root) return -1;
    if (root->data == key) return root->data;
    if (root->data < key) return Ceil(root->right, key);
    Element ceil = Ceil(root->left, key);
    
    return (ceil >= key) ? ceil: root->data;
}

Element Floor(Node root, Element key){
    if (!root) return MAX;
    if (root->data == key) return root->data;
    if (root->data > key) return Floor(root->left, key);
    Element floor = Floor(root->right, key);
    
    return (floor <= key) ? floor: root->data;
}

// Driver program to test above function
int main()
{
    Node root = CreateNode(8);
 
    root->left = CreateNode(4);
    root->right = CreateNode(12);
 
    root->left->left = CreateNode(2);
    root->left->right = CreateNode(6);
 
    root->right->left = CreateNode(10);
    root->right->right = CreateNode(14);

    Inorder(root);
    printf("\n");
 
    for(int i = 0; i < 16; i++){
        /*printf("ceil: %d  %d\n", i, Ceil(root, i));*/
        printf("floor: %d  %d\n", i, Floor(root, i));
    }
 
    return 0;
}
