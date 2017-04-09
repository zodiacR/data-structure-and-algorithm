#include <iostream>
#include <queue>

using namespace std;

typedef int Element;
struct node{
    Element data;
    struct node* left;
    struct node* right; 
    node() {}
    node(Element value){
        data = value;
        left = right = NULL;
    }
};

typedef struct node* Node;

int GetMaxWidth(Node t){
    int maxwidth = 0;
    int width = 0;
    queue<Node> Q;
    
    if (!t) return 0;

    Q.push(t);
    Node check = new node(-1);
    Q.push(check);

    while(!Q.empty()){
        Node tmp = Q.front();
        Q.pop();

        if (tmp->data != -1){
            width++;
            if (tmp->left){
                Q.push(tmp->left);
            } 
            if (tmp->right){
                Q.push(tmp->right);
            } 
        }

        else{
            if (width >= maxwidth)
                maxwidth = width;
            width = 0;

            if (Q.empty()) return maxwidth;
            Q.push(check);
        }
    }

    return maxwidth;
}
int main()
{
    Node root = new node(1);
    root->left	 = new node(2);
    root->right	 = new node(3);
    root->left->left = new node(4);
    //root->left->left->left = new node(4);
    //root->left->left->right = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(8); 
    root->right->right->left = new node(6); 
    root->right->right->right = new node(7);	 

    /*
    Constructed bunary tree is:
             1
            / \
          2    3
         / \	\
        4  5	 8 
                / \
               6   7
    */
    printf("Maximum width is %d \n", GetMaxWidth(root));
    return 0;
}
