#include <stdio.h>
#include <stdlib.h>

void PrintMaxActivities(int *s, int *f, int n){
    int i = 0;
    int k = i;

    printf("The following is a sequence of activities:\n");
    printf("%d", k);

    for (int i = 1; i < n; i++){
        if (s[i] >= f[k]){
            k = i;
            printf("%d", k);
        }
    }
    printf("\n");
}

// driver program to test above function
int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    PrintMaxActivities(s, f, n);
    return 0;
}
