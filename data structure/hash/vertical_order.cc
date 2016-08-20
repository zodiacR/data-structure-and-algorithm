#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node{
    int value;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

void Insert(Node* t, int value){
    Node n = (Node)malloc(sizeof(struct node));
    n->value = value;
    n->left = n->right = NULL;

    if (*t){
        Node current, parent;
        current = *t;
        int flag;

        while(current){
            parent = current; 
            if (value < current->value){
                current = current->left;
                flag = 0;
            } else if (value > current->value){
                current = current->right;
                flag = 1;
            } else return;
        }
        if(!flag) parent->left = n;
        else parent->right = n;

    } else{
        *t = n;
    }

}

void ClearTree(Node t){
    if (t){
        ClearTree(t->left);
        ClearTree(t->right);
    }
}

void Dispose(Node *t){
    if (*t){
        ClearTree(*t);
        *t = NULL;
    }
}

void VerticalOrder(Node t, map<int, vector<int> > &m, int hd){
    if (t){
        cout << t->value << ": " << hd << endl;
        m[hd].push_back(t->value);
        VerticalOrder(t->left, m, hd-1);
        VerticalOrder(t->right, m, hd+1);
    }
}

void Inorder(Node root){
    if (root){
        Inorder(root->left);
        cout << root->value << " ";
        Inorder(root->right);
    }
}

int main(){
    Node root = NULL;
    Insert(&root, 4);
    Insert(&root, 2);
    Insert(&root, 1);
    Insert(&root, 3);
    Insert(&root, 6);
    Insert(&root, 5);
    Insert(&root, 7);

    Inorder(root);
    cout << endl;

    int hd = 0;
    map<int ,vector<int> > m;
    VerticalOrder(root, m, hd);

    for(map<int, vector<int> >::iterator it = m.begin();
            it != m.end(); it++){
        for (int i = 0; i < it->second.size(); i++){
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
    
    Dispose(&root);

    return 0;
}
