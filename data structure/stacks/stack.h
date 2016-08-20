#ifndef _STACK_H
#define _STACK_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack s);
void push(Stack *s, int e);
int pop(Stack *s);
int top(Stack s);
void MakeEmpty(Stack *s);

struct Node{
    int element;
    PtrToNode next;
};
#endif
