#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define MAX 100

void Initialization(int* lookup){
    for (int i = 0 ; i < MAX; i++)
        lookup[i] = NIL;
}

int Fib(int n, int* table){
    if (table[n] == NIL){
        if (n <= 1) table[n] = n;
        else table[n] = Fib(n-1, table) + Fib(n-2, table); 
    }
    return table[n];
}

int main ()
{
    int n = 4;
    int table[MAX];
    Initialization(table);
    printf("Fibonacci number is %d \n", Fib(n, table));
    return 0;
}
