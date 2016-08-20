#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

Node MinValue(Node n){
    while(n->left != NULL)
       n = n->left;

    return n; 
}

Node CreateNode(Element value){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = value;
    n->left = n->right = NULL;
    /*printf("Finished\n");*/

    return n;
}

Node Insertion(Node root, Element value){
    if (!root) {
        root = CreateNode(value);
    }
    else{
        if (root->data > value) root->left = Insertion(root->left, value);
        if (root->data < value) root->right = Insertion(root->right, value);
    }

    return root;
}

Node Deletion(Node root, Element value){
    if (!root) return NULL;

    if (root->data > value) root->left = Deletion(root->left, value);
    else if (root->data < value) root->right = Deletion(root->right, value);
    else{
        if (!root->left) {
            Node tmp = root->right;
            free(root);
            return tmp; 
        }        
        else if (!root->right) {
            Node tmp = root->left;
            free(root);
            return tmp;
        }

        Node tmp = MinValue(root->right);
        root->data = tmp->data;
        root->right = Deletion(root->right, tmp->data);
    }

    return root;
}

void Inorder(Node root){
    if (!root) return;

    Inorder(root->left);
    /*printf("in\n");*/
    printf("%d ", root->data); 
    /*printf("left\n");*/
    Inorder(root->right);
}

void Postorder(Node root){
    if (!root) return;

    Postorder(root->left);
    /*printf("in\n");*/
    /*printf("left\n");*/
    Postorder(root->right);
    printf("%d ", root->data); 
}
