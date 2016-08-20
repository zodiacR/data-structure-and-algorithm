#ifndef _BALANCING_H
#define _BALANCING_H

struct StackRecord;
typedef struct StackRecord * Stack;

Stack CreateStack(unsigned capacity);
int IsFull(Stack s);
int IsEmpty(Stack s);
void push(Stack s, char e);
char pop(Stack s);
char top(Stack s);
void MakeEmpty(Stack *s);

#endif

#define EMPTYTOS -1

struct StackRecord{
    unsigned capacity;
    int top;
    char *array;
};
