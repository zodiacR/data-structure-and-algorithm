#include <iostream>
#include <stack>

using namespace std;

template <class T>
struct node {
    T data;
    struct node* left;
    struct node* right;
    node(T value){
        data = value;
        left = right = NULL;
    }
};

template <class T>
using Node = struct node<T>*;

template <class T>
void pushLeft(Node<T> root, stack<Node<T> >& s){
    while(root){
        s.push(root);
        root = root->left;
    } 
}

template <class T>
void Merge(Node<T> root1, Node<T> root2){
    stack<Node<T> > s1; 
    stack<Node<T> > s2; 

    //s1.push(root1);
    //s2.push(root2);
    pushLeft(root1, s1);
    pushLeft(root2, s2);

    while(!s1.empty() && !s2.empty()){
        Node<T> t1 = s1.top();
        Node<T> t2 = s2.top();

        if (t1->data < t2->data){
            cout<< t1->data << "->";
            s1.pop();
            pushLeft(t1->right, s1);
        }
        else{
            cout<< t2->data << "->";
            s2.pop();
            pushLeft(t2->right, s2);
        }
    }

    while(!s1.empty()) {
        Node<T> t = s1.top();
        cout<< t->data << "->";
        s1.pop();
        pushLeft(t->right, s1);
    }

    while(!s2.empty()) {
        Node<T> t = s2.top();
        cout<< t->data << "->";
        s2.pop();
        pushLeft(t->right, s2);
    }

    cout << endl;
}

template <class T>
Node<T> Insertion(Node<T> root, T value){
    if (!root) return new node<T>(value);

    Node<T> ptraversal = root;
    Node<T> pcurrentPrt = root;
    int flag;

    while(ptraversal){
        pcurrentPrt = ptraversal;
        if (value < ptraversal->data){
            ptraversal = ptraversal->left;
            flag = 1;
        }
        else{
            ptraversal = ptraversal->right;
            flag = 0;
        }
    }

    if (flag) pcurrentPrt->left = new node<T>(value);
    else pcurrentPrt->right = new node<T>(value);

    return root;
}

template <class T>
Node<T> Dispose(Node<T> root){
    if (root){
        root->left = Dispose(root->left);
        root->right = Dispose(root->right);
        delete root;

        return NULL;
    }
}

template <class T>
void Inorder(Node<T> root){
    if(root){
        Inorder(root->left);
        cout<<root->data<< " ";
        Inorder(root->right);
    }
}

int main(){
    Node<int> root1, root2;
    root1 = root2 = NULL;
    root2 = Insertion(root2, 4);
    root2 = Insertion(root2, 2);
    root2 = Insertion(root2, 6);
    root2 = Insertion(root2, 1);
    root2 = Insertion(root2, 3);
    root2 = Insertion(root2, 5);
    root2 = Insertion(root2, 7);
    Inorder(root2);
    cout<<endl;
 
  	root1 = Insertion(root1, 100);
    root1 = Insertion(root1, 90);
    root1 = Insertion(root1, 105);
    root1 = Insertion(root1, 70);
    root1 = Insertion(root1, 95);
    root1 = Insertion(root1, 103);
    root1 = Insertion(root1, 106);
    Inorder(root1);
    cout<<endl;
    Merge(root1,root2);

    root1 = Dispose(root1);
    root2 = Dispose(root2);

    return 0;
}
