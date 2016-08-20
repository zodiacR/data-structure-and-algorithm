#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    int height;
    struct node *left, *right; 
}Node;

Node* CreateNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    n->height = 1;

    return n;
}

int height(Node *node) {
    if (!node) return 0; 
    return node->height;
}

int max(int a, int b) { return a>b?a:b; }

int getBalance(Node *root) { 
    if (!root) return 0; 
    return height(root->left)- height(root->right);
}

Node* righRotate(Node *z) {
    Node* y = z->left;
    Node* T3 = y->right;

    z->left = T3;
    y->right = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* leftRotate(Node *z) {
    Node* y = z->right;
    Node* T2 = y->left;

    z->right = T2;
    y->left = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int val) {
    if (!root) return CreateNode(val);

    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    root->height = max(height(root->left), height(root->right)) + 1;

    int balanced = getBalance(root);

    if (balanced > 1 && val < root->left->val)
        root = righRotate(root);
    else if (balanced > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        root = righRotate(root);
    }
    else if (balanced < -1 && val > root->right->val) {
        root = leftRotate(root);
    }
    else if (balanced < -1 && val < root->right->val) {
        root->right = righRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  Node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
  printf("\n");
 
  return 0;
}
