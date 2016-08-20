#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *num, int x, int y) {
    char tmp = num[x];
    num[x] = num[y];
    num[y] = tmp;
}

void Next(char *num, int n) {
    int idx = 0;
    for (int i = n-1; i > 0; i--) {
        if (num[i] > num[i-1]) {
            idx = i;
            break;
        }      
    }

    if (idx == 0) {
        printf("Impossible\n");
    } else {
        int small = idx;
        int x = num[idx-1];
        for (int j = idx+1; j < n; j++) {
            if (num[j] > x && num[j] < num[small])
                small = j;
        } 
        swap(num, small, idx-1);

        int i = idx, j = n-1;
        while (i < j) {
            swap(num, i, j);
            i++;
            j--;
        }

        printf("%s\n", num);
    }
}
// Driver program to test above function
int main()
{
    char digits[] = "21897";
    int n = strlen(digits);
    Next(digits, n);
    return 0;
}
