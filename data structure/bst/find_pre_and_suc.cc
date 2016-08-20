#include <iostream>

using namespace std;

template <class T>
struct node{
    T data;
    struct node* left;
    struct node* right;
    node(T value){
        data = value;
        left = right = NULL; 
    }
};

template<class T>
using Node = struct node<T>*;

template<class T>
Node<T> Insert(Node<T> root, T value){
    if (!root){
        root = new node<T>(value);
    } 
    else{
        if(value < root->data) root->left = Insert(root->left, value);
        if(value > root->data) root->right = Insert(root->right, value);
    }

    return root;
}

template<class T>
void FindPreSuc(Node<T> root, Node<T> &pre, Node<T> &suc, T key){
    if (!root) return; 
    if (root->data == key){
        if (root->left){
            Node<T> tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }
        if (root->right){
            Node<T> tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    if (key < root->data){
        suc = root;
        FindPreSuc(root->left, pre, suc, key);
    }
    else {
        pre = root;
        FindPreSuc(root->right, pre, suc, key);
    }
}

template<class T>
void Inorder(Node<T> root){
    if (!root) return;

    Inorder(root->left);
    cout<< root->data <<" ";
    Inorder(root->right);
}

int main(){
    int key = 30;

    Node<int> root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    //Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);
    Inorder(root);
    cout<<endl;

    Node<int> pre = NULL, suc = NULL;
 
    FindPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor" << endl;
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor" << endl;
    return 0;
}
