#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void swap(Element *first, Element *second){
    Element tmp;
    tmp = *first;
    *first = *second;
    *second = tmp;
}

void CorrectBSTUtil(Node root, Node* first, Node* middle,
                    Node* last, Node* prev){
    if(root){
        // Left subtree
        CorrectBSTUtil(root->left, first, middle, last, prev);
        if (*prev && root->data < (*prev)->data) {
            if(!(*first)){
                *first = *prev;
                *middle = root;
            }else {
                *last = root;
            }
        }
        *prev = root;

        CorrectBSTUtil(root->right, first, middle, last, prev);
    }
}

void CorrectBST(Node root){
    Node first, middle, last, prev;
    first = middle = last = prev = NULL;

    CorrectBSTUtil(root, &first, &middle, &last, &prev);

    if(first && last)
        swap(&(first->data), &(last->data));
    else if (first && middle)
        swap(&(first->data), &(middle->data));
}

/* Driver program to test above functions*/
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    struct node *root = CreateNode(6);
    root->left        = CreateNode(10);
    root->right       = CreateNode(2);
    root->left->left  = CreateNode(1);
    root->left->right = CreateNode(3);
    root->right->right = CreateNode(12);
    root->right->left = CreateNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    Inorder(root);
    printf("\n");
 
    CorrectBST(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    Inorder(root);
    printf("\n");
 
    return 0;
}
