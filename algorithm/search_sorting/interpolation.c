#include <stdio.h>
#include <stdlib.h>

int Interpolation(int* arr, int x, int n){
    int l = 0;
    int r = n-1;
    while (l <= r){
        if (l == r){
            if (arr[l] == x) return 1;
            else return 0;
        }

        int c = (x-arr[l]) / (arr[r]-arr[l]);
        if (c < 0 || c > 1) return 0;

        int mid = l + c*(r-l);

        if (arr[mid] > x) r = mid-1;
        else if (arr[mid] < x) l = mid + 1;
        else return 1;
    }

    return 0;
}

int main(){
    int arr[] = {201, 209, 232, 233, 332, 399, 400};
    int n = sizeof(arr) / sizeof(*arr);
    if (Interpolation(arr, 401, n))
        printf("Found it\n");
    else printf("Not Found\n");
}
