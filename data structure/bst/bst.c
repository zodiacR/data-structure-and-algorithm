#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    /*root = Insertion(root, 50);*/
    /*root = Insertion(root, 30);*/
    /*root = Insertion(root, 20);*/
    /*root = Insertion(root, 40);*/
    /*root = Insertion(root, 70);*/
    /*root = Insertion(root, 60);*/
    /*root = Insertion(root, 80);*/
    root = Insertion(root, 4);
    root = Insertion(root, 1);
    root = Insertion(root, 0);
    root = Insertion(root, 2);
    root = Insertion(root, 3);
    root = Insertion(root, 7);
    root = Insertion(root, 5);
    root = Insertion(root, 6);
    root = Insertion(root, 8);
    root = Insertion(root, 9);
 
    printf("Inorder traversal of the given tree \n");
    Postorder(root);
 
    /*printf("\nDelete 20\n");*/
    /*root = Deletion(root, 20);*/
    /*printf("Inorder traversal of the modified tree \n");*/
    /*Inorder(root);*/
 
    /*printf("\nDelete 30\n");*/
    /*root = Deletion(root, 30);*/
    /*printf("Inorder traversal of the modified tree \n");*/
    /*Inorder(root);*/
 
    /*printf("\nDelete 50\n");*/
    /*root = Deletion(root, 50);*/
    /*printf("Inorder traversal of the modified tree \n");*/
    /*Inorder(root);*/

    printf("\nDelete 3\n");
    root = Deletion(root, 3);
    printf("Inorder traversal of the modified tree \n");
    Inorder(root);
 
    printf("\nDelete 7\n");
    root = Deletion(root, 7);
    printf("Inorder traversal of the modified tree \n");
    Inorder(root);
 
    printf("\nDelete 0\n");
    root = Deletion(root, 0);
    printf("Inorder traversal of the modified tree \n");
    Inorder(root);
 
    return 0;
}

