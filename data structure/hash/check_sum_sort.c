#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int hasArrayTwoCandidates(int *A, int n, int sum){

    int l = 0;
    int r = n-1;

    while (l < r){
        if (A[l]+A[r] == sum) return 1;
        else if (A[l]+A[r] < sum) l++;
        else r--;
    }

    return 0;
}

int main(){
    int A[] = {1, 4 ,45, 6, 10, -8};
    int sum = 16;
    int n = sizeof(A) / sizeof(A[0]);
    qsort(A, n, sizeof(int), cmpfunc);

    if( hasArrayTwoCandidates(A, n, sum))
        printf("Array has two elements with sum 16\n");
    else
        printf("Array doesn't have two elements with sum 16\n");

    return 0;
}
