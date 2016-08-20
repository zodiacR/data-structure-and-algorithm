#include <stdio.h>
#include <stdlib.h>

typedef int Element;

struct node{
    Element data;
    struct node* pre;
    struct node* next;
};

typedef struct node* Node;

void insert(Node *head, Element value){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = value;
    n->pre = n->next = NULL;

    if(!*head) *head = n;
    else {
        n->next = *head;
        (*head)->pre = n;
        *head = n;
    }
}

Node convertion(Node *head, int n){
    if (n<=0) return NULL;
    Node left = convertion(head, n/2);
    Node root = *head;
    *head = (*head)->next;
    root->pre = left;
    root->next = convertion(head, n-n/2-1);

    return root;
}

void Preorder(Node root){
    if (root){
        printf("%d ", root->data);
        Preorder(root->pre);
        Preorder(root->next);
    }

}
void Inorder(Node root){
    if (root){
        Inorder(root->pre);
        printf("%d ", root->data);
        Inorder(root->next);
    }

}

void displayList(Node head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int countNode(Node head){
    int i = 0;
    while(head){
        i++;
        head = head->next;
    }

    return i;
}

int main()
{
    /* Start with the empty list */
    Node head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 7->6->5->4->3->2->1 */
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
 
    printf("\n Given Linked List ");
    displayList(head);
 
    /* Convert List to BST */
    Node root = convertion(&head, countNode(head));
    printf("\n PreOrder Traversal of constructed BST ");
    Preorder(root);
    printf("\n Inorder ");
    Inorder(root);
    printf("\n");
 
    return 0;
}
