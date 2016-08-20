#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int size;
    int *arr;
    int top1, top2;
}Stack;

void push1(Stack *s, int val) {
    if (s->top1 < s->top2 - 1){
        s->top1++;
        s->arr[s->top1] = val;
    } else {
        printf("Overflow\n");
        return;
    }
}

void push2(Stack *s, int val) {
    if (s->top1 < s->top2 - 1){
        s->top2--;
        s->arr[s->top2] = val;
    } else {
        printf("Overflow\n");
        return;
    }
}

int pop1(Stack *s) {
    if (s->top1 != -1) {
        int top = s->arr[s->top1];
        s->top1--;

        return top;
    } else {
        printf("Overflow\n");
        return INT_MIN;
    }
}

int pop2(Stack *s) {
    if (s->top2 != s->size) {
        int top = s->arr[s->top2];
        s->top2++;

        return top;
    } else {
        printf("Overflow\n");
        return INT_MIN;
    }
}

Stack * CreateStack(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->size = n;
    s->top1 = -1;
    s->top2 = n;
    s->arr = (int*)malloc(sizeof(int) * n);

    return s;
}

/* Driver program to test twStacks class */
int main()
{
    Stack *s = CreateStack(5);
    push1(s, 5);
    push2(s, 10);
    push2(s, 15);
    push1(s, 11);
    push2(s, 7);
    printf("Popped element from stack1 is %d\n", pop1(s));
    push2(s, 40);
    printf("\nPopped element from stack2 is %d\n", pop2(s));
    push2(s, 60);
    push2(s, 90);
    printf("\nPopped element from stack2 is %d\n", pop2(s));
    printf("Popped element from stack1 is %d\n", pop1(s));
    printf("Popped element from stack1 is %d\n", pop1(s));
    return 0;
}
