#include "postfix.h"
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

int priority(char c){
    switch(c){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 3;
}

int main()
{
    Stack stack = CreateStack(20);
 
    char expr[] = "(a+b)*c^k+d*(e+f)*g";
    char operator;

    char *index = expr;

    while(*index){
        if (*index < 97 || *index > 122){
            if (*index == '('){
                push(stack, *index);
            }
            else{
                if (*index == ')'){
                    while((operator=pop(stack)) != '(')
                        printf("%c", operator);
                }
                else{ 
                    while(!IsEmpty(stack) && priority(*index) <= priority(top(stack)))
                        printf("%c", pop(stack));

                    push(stack, *index);
                }
            }
        }
        else
            printf("%c", *index);
        ++index;
    }
    while (!IsEmpty(stack))
        printf("%c", pop(stack));
    printf("\n");
 
    return 0;
}
