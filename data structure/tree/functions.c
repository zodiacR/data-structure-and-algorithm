#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "tree.h"
#include "queue.h"

void Insert(Tree t, Element e){
    if (!*t) {
        CreateTree(t, e);
        return;
    }

    Node* temp = *t;
    Node* parent = *t;
    int flag = 0;
    
    while (temp) {
        parent = temp;
        if (e >= temp->data) {
            temp = temp->right;
            flag = 1;
        }
        else {
            temp = temp->left;
            flag = 0;
        }
    }

    Node* n = (Node*)malloc(sizeof(Node));
    n->data = e;
    n->left = n->right = NULL;

    if (!flag) parent->left = n;
    else parent->right = n;

}

void CreateTree(Tree t, Element e){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->right = node->left = NULL;

    *t = node;
}

// Breadth First Search
void BFS(Node* n){
    if (!n) return;

    Queue* q = CreateQueue(30); 
    Node *temp = n;

    while (temp){
        printf("%d ", temp->data);

        if (temp->left){
            /*printf("Left: %p\n", temp->left);*/
            Enqueue(q, temp->left);
        }
        if (temp->right){
            /*printf("Right: %p\n", temp->right);*/
            Enqueue(q, temp->right);
        }

        temp = Dequeue(q);
    }

    q = DisposeQueue(q);
    printf("\n");
}

void Preorder(Node* n){
    if (!n) return;

    printf("%d ", n->data);
    Preorder(n->left);
    Preorder(n->right);
}

void Inorder(Node* n){
    if (!n) return;

    Inorder(n->left);
    printf("%d ", n->data);
    Inorder(n->right);
}

void Postorder(Node* n){
    if (!n) return;

    Postorder(n->left);
    Postorder(n->right);
    printf("%d ", n->data);
}

void DeTree(Tree t){
    Dispose(*t);

    *t = NULL;
}

void Dispose(Node* n){
    if (!n) return;

    Dispose(n->left);
    Dispose(n->right);
    free(n); 
}

// Queue
Queue* CreateQueue(int max_size){
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->size = queue->front = 0;
    queue->rear = max_size-1;
    queue->capacity = max_size;
    queue->q = (Object**)malloc(sizeof(Object*) * max_size);

    return queue;

}

void Enqueue(Queue *q, Object* e){
    if (IsFull(q)) return;

    /*printf("In: %d\n", e->data);*/
    q->rear = (q->rear + 1) % q->capacity;
    q->q[q->rear] = e;
    q->size++;

}

Object* Dequeue(Queue *q){
    if(IsEmpty(q)) return NULL;  
    
    Object *i = q->q[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    /*printf("Out: %d\n", i->data);*/

    return i;
}

int IsFull(Queue *q) {
    return q->size == q->capacity;
}

int IsEmpty(Queue *q) {
    return q->size == 0;
}

Queue* DisposeQueue(Queue* q){
    free(q->q);
    free(q);

    return NULL;
}

Node* pop(Stack *s) {
    if(IsEmptyStack(*s))
        return NULL;
    Item tmp = (*s);
    (*s) = (*s)->next;

    Node* n = tmp->n;
    free(tmp);

    return n;
}

void push(Stack *s, Node* n) {
    Item i = (Item)malloc(sizeof(struct item));

    i->n = n;
    i->next = (*s);
    (*s) = i;
}

int IsEmptyStack(Stack s){
    return (s == NULL);
}

void MakeEmpty(Stack *s){
    while(!IsEmptyStack(*s))
       pop(s); 
}
