#include <stdio.h>
#include <stdlib.h>

int isSubsetSum(int *set, int n, int sum) {
    int table[n+1][sum+1];

    for (int i = 0; i <= n; i++) {
        table[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++){
        table[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] > sum) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = table[i-1][j] || table[i-1][j-set[i-1]];
            }
        }
    }

    return table[n][sum];
}

// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 18;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum))
     printf("Found a subset with given sum\n");
  else
     printf("No subset with given sum\n");
  return 0;
}
