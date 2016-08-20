#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    Stack s = NULL;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Pop out:%d\n", pop(&s));
    printf("Top:%d\n", top(s));
    printf("%d\n", IsEmpty(s));
    MakeEmpty(&s);
    printf("%d\n", IsEmpty(s));

    return 0;
}

int IsEmpty(Stack s) { return s == NULL; }

void push(Stack *s, int e)
{
    PtrToNode n = (PtrToNode)malloc(sizeof(struct Node));
    n->element = e;

    n->next = *s;
    *s = n;
}

int pop(Stack *s){
    if (IsEmpty(*s))
        return INT_MIN;
    PtrToNode tmp = *s;
    *s = (*s)->next;

    int data = tmp->element;
    free(tmp);

    return data;
}

int top(Stack s)
{
    if (IsEmpty(s))
        return INT_MIN;
    return s->element; 
}

void MakeEmpty(Stack* s){
    while (!IsEmpty(*s))
        pop(s);
}
