#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, int first, int second) {
    char tmp = a[first];
    a[first] = a[second];
    a[second] = tmp;
}

void Permutation(char *str, int l, int r){
    if (l == r) {
        printf("%s\n", str);
    }

    else {
        for (int i = l; i <= r; i++) {
            swap(str, l, i);
            Permutation(str, l+1, r);
            swap(str, l, i);
        }
    }
}

/* Driver program to test above functions */
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    Permutation(str, 0, n-1);
    return 0;
}
