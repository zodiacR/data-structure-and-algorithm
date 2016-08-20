#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int l, int h, int key) {
    if (l > h) return -1;

    int mid = (l+h) / 2;
    if (arr[mid] == key) return mid;

    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid-1, key);
        else
            return search(arr, mid+1, h, key);
    }

    else {
        if (key >= arr[mid] && key <= arr[h])
            return search(arr, mid+1, h, key);
        else
            return search(arr, l, mid-1, key);
    }
}

// Driver program
int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 1;
    int i = search(arr, 0, n-1, key);
    if (i != -1) printf("Found it, and its index is %d\n", i);
    else printf("Not found it\n");
}
