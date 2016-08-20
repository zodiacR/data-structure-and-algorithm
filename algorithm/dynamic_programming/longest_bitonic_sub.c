#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) a>b?a:b

void IncSeq(int *lis_seq, int idx, int *arr) {
    if (lis_seq[idx] != idx) {
        IncSeq(lis_seq, lis_seq[idx], arr);
        printf("%d ", arr[lis_seq[idx]]);
    }
}

void DecSeq(int *lds_seq, int idx, int *arr) {
    if (lds_seq[idx] != idx) {
        printf("%d ", arr[lds_seq[idx]]);
        DecSeq(lds_seq, lds_seq[idx], arr);
    }
}

int LBS(int *arr, int n) {
    int lis[n], lds[n];
    int lis_seq[n], lds_seq[n];

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        lds[i] = 1;
        lis_seq[i] = i;
        lds_seq[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && lis[i] < lis[j]+1){
                lis[i] = lis[j]+1;
                lis_seq[i] = j;
            }
        }
    }


    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if (arr[j] < arr[i] && lds[i] < lds[j]+1){
                lds[i] = lds[j]+1;
                lds_seq[i] = j;
            }
        }
    }

    int max = lis[0]+lds[0]-1;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (max < lis[i]+lds[i]-1){
            max = lis[i]+lds[i]-1; 
            idx = i;
        }
    }
    IncSeq(lis_seq, idx, arr);
    printf("%d ", arr[idx]);
    DecSeq(lds_seq, idx, arr);
    printf("\n");

    return max;
}

/* Driver program to test above function */
int main()
{
    /*int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};*/
    int arr[] = {5, 12, 84, 80, 63, 77, 62, 68};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LBS is %d\n", LBS( arr, n ) );
    return 0;
}
