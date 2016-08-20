#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NA INT_MIN

void Move2End(int *arr, int n){
    for(int i = n-1, j = n-1; i >= 0; i--) {
        if (arr[i] != NA) {
            arr[j] = arr[i];
            j--;
        }
    }
}

void Merge(int *mPlusN, int *N, int m, int n) {
    int i = 0;
    int j = n;
    int k = 0;

    /*while (k < n+m) {*/
        /*if ((mPlusN[j] < N[i] && j < n+m) || i == n){*/
            /*mPlusN[k] = mPlusN[j];*/
            /*k++;*/
            /*j++;*/
        /*} else {*/
            /*mPlusN[k] = N[i];*/
            /*k++;*/
            /*i++;*/
        /*}*/
    /*}*/

    while (i < n && j < n+m){
        if (mPlusN[j] < N[i]){
            mPlusN[k] = mPlusN[j];
            k++;
            j++;
        } else {
            mPlusN[k] = N[i];
            i++;
            k++;
        }
    }

    while (i < n) {
        mPlusN[k] = N[i];
        i++;
        k++;
    }

    while (j < n+m) {
        mPlusN[k] = mPlusN[j];
        j++;
        k++;
    }
}

void Print(int *mPlusN, int size) {
    for (int i =0; i < size; i++)
        printf("%d ", mPlusN[i]);

    printf("\n");
}

/* Driver function to test above functions */
int main()
{
  /* Initialize arrays */
  int mPlusN[] = {2, 8, NA, NA, NA, NA, NA, 15, 20};
  int N[] = {5, 7, 9, 13, 25};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
 
  /*Move the m elements at the end of mPlusN*/
  Move2End(mPlusN, m+n);
 
  /*Merge N[] into mPlusN[] */
  Merge(mPlusN, N, m, n);
 
  /* Print the resultant mPlusN */
  Print(mPlusN, m+n);
 
  return 0;
}
