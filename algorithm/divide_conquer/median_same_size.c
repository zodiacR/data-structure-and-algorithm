#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a>b?a:b;
}

int min(int a, int b) {
    return a<b?a:b;
}

int median(int *arr, int n) {
    if (n % 2 == 0) return (arr[n/2]+arr[n/2-1])/2;
    else return arr[n/2];
}

int MedianOfTwo(int *arr1, int *arr2, int n) {
    if (n <= 0) return -1;

    else if (n == 1) return (arr1[0]+arr2[0])/2;
    
    else if (n == 2) return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

    else {
        int m1 = median(arr1, n);
        int m2 = median(arr2, n);

        if (m1 == m2) return m1;

        else if (m1 < m2) {
            if (n%2 == 0) {
                return MedianOfTwo(arr1+n/2-1, arr2, n-n/2+1);
            }
            else return MedianOfTwo(arr1+n/2, arr2, n-n/2);
        }
        else {
            if (n%2 == 0) return MedianOfTwo(arr1, arr2+n/2-1, n-n/2+1);
            else return MedianOfTwo(arr1, arr2+n/2, n-n/2);
        }
    }
}

/* Driver program to test above function */
int main()
{
    /*int ar1[] = {1, 2, 3, 6};*/
    /*int ar2[] = {4, 6, 8, 10};*/
    int ar1[] = {0, 1, 2, 8, 9};
    int ar2[] = {0, 5, 6, 7, 8};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d\n", MedianOfTwo(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}
