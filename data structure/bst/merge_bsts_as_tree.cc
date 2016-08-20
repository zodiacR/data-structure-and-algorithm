#include <iostream>
using namespace std;

typedef int Element;
struct node{
    Element data;
    struct node *left;
    struct node* right;
};

typedef struct node* Node;


void BST2Arr(Node root, Element *arr, int* index){
    if (root){
        BST2Arr(root->left, arr, index);
        arr[(*index)++] = root->data;
        BST2Arr(root->right, arr, index);
    }
}


Node Arr2BST(Element *arr, int start, int end){
    if (start > end) return NULL;

    Node root = (Node)malloc(sizeof(struct node));
    int middle = (start + end) / 2;
    root->data = arr[middle];

    root->left = Arr2BST(arr, start, middle-1);
    root->right = Arr2BST(arr, middle+1, end);

    return root;
}

Element* MergeArr(Element *first, Element *second, int n, int m){
    int i, j, k;
    i = j = k = 0; 
    Element *merge = new Element[n+m];

    while (i < n && j < m){
        if(first[i] < second[j]){
            merge[k] = first[i];
            i++;
        }
        else{
            merge[k] = second[j];
            j++;
        }
        k++;
    }

    while (i < n){
            merge[k] = first[i];
            i++;
            k++;
    }

    while (j < m){
            merge[k] = second[j];
            j++;
            k++;
    }

    return merge;
}

Node MergeTrees(Node root1, Node root2, int n, int m){
    Element *first = new Element[n];
    int i = 0;
    BST2Arr(root1, first, &i);

    i = 0;
    Element *second = new Element[m];
    BST2Arr(root2, second, &i);

    Element *merge = MergeArr(first, second, n, m);
    delete[] first;
    delete[] second;

    return Arr2BST(merge, 0, n+m-1);
}

Node newNode(int data)
{
    Node node = (Node)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

void Inorder(Node root){
    if (root){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

/* Driver program to test above functions*/
int main()
{
    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    Node root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);
 
    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    Node root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);
 
    Node mergedTree = MergeTrees(root1, root2, 5, 3);
 
    printf ("Following is Inorder traversal of the first tree \n");
    Inorder(root1);
    printf("\n");

    printf ("Following is Inorder traversal of the second tree \n");
    Inorder(root2);
    printf("\n");

    printf ("Following is Inorder traversal of the merged tree \n");
    Inorder(mergedTree);
    printf("\n");

    return 0;
}
