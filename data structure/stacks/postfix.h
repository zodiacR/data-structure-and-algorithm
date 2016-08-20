#ifndef _POSTFIX_H
#define _POSTFIX_H

struct StackRecord;
typedef struct StackRecord * Stack;

Stack CreateStack(unsigned capacity);
int IsFull(Stack s);
int IsEmpty(Stack s);
void push(Stack s, char e);
char pop(Stack s);
char top(Stack s);
void MakeEmpty(Stack *s);
int priority(char c);

#endif

#define EMPTYTOS -1

struct StackRecord{
    unsigned capacity;
    int top;
    char *array;
};
