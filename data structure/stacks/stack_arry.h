#ifndef _STACK_ARRAY_H
#define _STACK_ARRAY_H

struct StackRecord;
typedef struct StackRecord * Stack;

Stack CreateStack(unsigned capacity);
int IsFull(Stack s);
int IsEmpty(Stack s);
void push(Stack s, int e);
int pop(Stack s);
int top(Stack s);
void MakeEmpty(Stack *s);

#endif

#define EMPTYTOS -1

struct StackRecord{
    unsigned capacity;
    int top;
    int *array;
};
