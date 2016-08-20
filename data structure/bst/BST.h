#ifndef BST_H
#define BST_H

typedef int Element;
struct node;
typedef struct node* Node;
Node CreateNode(Element value);
Node Insertion(Node root, Element value);
Node Deletion(Node root, Element value);
void Inorder(Node root);
void Postorder(Node root);

struct node{
    Element data;
    struct node* left;
    struct node* right;
};
#endif

