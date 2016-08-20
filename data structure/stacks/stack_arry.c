#include "stack_arry.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Stack CreateStack(unsigned capacity){
    Stack s = (Stack)malloc(sizeof(struct StackRecord));
    s->capacity = capacity;
    s->top = EMPTYTOS;
    s->array = (int *)malloc(sizeof(int) * capacity);

    return s;
}

int IsEmpty(Stack s){
    return (s->top == EMPTYTOS);
}

int IsFull(Stack s){
    return (s->top == s->capacity-1);
}

void push(Stack s, int e){
    if (IsFull(s))
        return;
    s->array[++s->top] = e;
}

int pop(Stack s){
    if (IsEmpty(s))
        return INT_MIN;
    return s->array[s->top--];
}

int top(Stack s){
    if (IsEmpty(s))
        return INT_MIN;
    return s->array[s->top];
}

void MakeEmpty(Stack *s){
    if (*s != NULL){
        free((*s)->array);
        free(*s);
        *s = NULL;
    }
}

int main()
{
    Stack stack = CreateStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    printf("Top item is %d\n", top(stack));
    printf("%d\n", stack == NULL);
    MakeEmpty(&stack);
    printf("%d\n", stack == NULL);
 
    return 0;
}
