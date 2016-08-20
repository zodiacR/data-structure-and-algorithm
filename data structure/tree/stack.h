#ifndef _STACK_H
#define _STACK_H

#include "tree.h"
struct item;
typedef struct item* Item;
typedef Item Stack;

Node* pop(Stack *s);
void push(Stack *s, Node* e);
int IsEmptyStack(Stack s);
void MakeEmpty(Stack *s);

struct item{
    Node* n;
    struct item *next;
};
#endif
