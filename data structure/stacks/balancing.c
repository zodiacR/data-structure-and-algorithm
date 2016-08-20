#include "balancing.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Stack CreateStack(unsigned capacity){
    Stack s = (Stack)malloc(sizeof(struct StackRecord));
    s->capacity = capacity;
    s->top = EMPTYTOS;
    s->array = (char *)malloc(sizeof(char) * capacity);

    return s;
}

int IsEmpty(Stack s){
    return (s->top == EMPTYTOS);
}

int IsFull(Stack s){
    return (s->top == s->capacity-1);
}

void push(Stack s, char e){
    if (IsFull(s))
        return;
    s->array[++s->top] = e;
}

char pop(Stack s){
    if (IsEmpty(s))
        return 0;
    return s->array[s->top--];
}

char top(Stack s){
    if (IsEmpty(s))
        return 0;
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
 
    char context[] = "([{}[]{}]){(";
    char *index = context;

    while(*index){
        switch (*index){
            case '(':
            case '[':
            case '{':
                push(stack, *index);
                break;
            case ')':
                if (pop(stack) != '('){
                    printf("No match!\n");
                    return 0;
                } 
                break;
            case ']':
                if (pop(stack) != '['){
                    printf("No match!\n");
                    return 0;
                }
                break;
            case '}':
                if (pop(stack) != '{'){
                    printf("No match!\n");
                    return 0;
                }
                break;
        }
        index++;
    }
    if (!IsEmpty(stack))
        printf("Not empty!\n");
    else
        printf("All match\n");

    MakeEmpty(&stack);
 
    return 0;
}

