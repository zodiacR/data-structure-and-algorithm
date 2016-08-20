#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPS(char *p, int M, int *lps){
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < M){
        if (p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if (len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *p, char *txt){
    int M = strlen(p);
    int N = strlen(txt);

    int *lps = (int*)malloc(sizeof(int)*M);
    computeLPS(p, M, lps);

    int j = 0;
    int i = 0;

    while (j < N){
        if (p[i] == txt[j]){
            i++;
            j++;
        }

        if ( i == M){
            printf("Found pattern at index %d\n", j-i);
            i = lps[i-1]; 
        } else if(j < N && p[i] != txt[j]){
            if (i) i = lps[i-1];
            else j++;  
        }
    }
}

// Driver program to test above function
int main()
{
   char *txt = "AABAACAADAABAAABAA";
   char *pat = "AABA";
   KMP(pat, txt);
   return 0;
}
