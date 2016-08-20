#ifndef TREE_H
#define TREE_H
struct node;
typedef struct node Node;
typedef Node** Tree;
typedef int Element;

void CreateTree(Tree t, Element e);
void Insert(Tree t, Element e);
void Preorder(Node* n);
void Postorder(Node* n);
void Inorder(Node* n);
void DeTree(Tree t);
void Dispose(Node* t);
void BFS(Node* n);
int DiameterOpt(Node *n, int* height);
int max(int a, int b);

struct node{
    Element data;
    struct node* left;
    struct node* right;
};
#endif
