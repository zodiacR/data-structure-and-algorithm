#include <iostream>
#include "BST.h"
#include <stack>

using namespace std;

Element kth_smallest(Node root, int k){
    stack<Node> S;

    bool done = false;
    while(!done){
        if (root){
            while(root){
                S.push(root);
                root = root->left;
            }
        }
        else{
            if (!S.empty()){
                Node tmp = S.top();
                S.pop();
                if(--k == 0) return tmp->data;
                //cout << tmp->data << " ";
                root = tmp->right;
            }
            else done = true;
        }
    }

    //cout << endl;
}

void Inorder(Node root){
    stack<Node> S;

    bool done = false;
    while(!done){
        if (root){
            while(root){
                S.push(root);
                root = root->left;
            }
        }
        else{
            if (!S.empty()){
                Node tmp = S.top();
                S.pop();
                cout << tmp->data << " ";
                root = tmp->right;
            }
            else done = true;
        }
    }

    cout << endl;
}

int main(){
    Element ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n = sizeof(ele) / sizeof(ele[0]);
    Node root = NULL;

    for (int i = 0; i != n; i++)
        root = Insertion(root, ele[i]);

    Inorder(root);
    cout << kth_smallest(root, n) << endl;
}

Node Insertion(Node root, Element value){
    if (!root) return CreateNode(value);

    Node ptraversal = root;
    Node currentPrt = root;
    int flag;

    while(ptraversal){
        currentPrt = ptraversal; 
        if (value < ptraversal->data){
            ptraversal = ptraversal->left;
            flag = 1;
        } else {
            ptraversal = ptraversal->right;
            flag = 0;
        }
    }

    if (flag) currentPrt->left = CreateNode(value);
    else currentPrt->right = CreateNode(value);

    return root;
}

Node CreateNode(Element value){
    Node n = (Node)malloc(sizeof(struct node));
    n->data = value;
    n->left = n->right = NULL;

    return n;
}

