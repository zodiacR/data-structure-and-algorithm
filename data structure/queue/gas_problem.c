#include <stdio.h>
#include <stdlib.h>

typedef struct petrolPump{
    int petrol;
    int distance;
}Gas;

int CanCompleteCircuit(Gas arr[], int n){
    int UptoNow = 0;
    int total = 0;
    int start = 0;

    for(int i = 0; i < n; i++){
        int delta = arr[i].petrol - arr[i].distance;
        if (UptoNow >= 0) UptoNow += delta;
        else{
            UptoNow = delta;
            start = i;
        } 

        total += delta;
    }

    return total >= 0 ? start:-1;
}

int main()
{
    /*Gas arr[] = {{6, 4}, {3, 6}, {7, 3}};*/
    /*Gas arr[] = {{1, 2}, {5, 4}, {4, 2}, {4, 2}, {1, 2}};*/
    Gas arr[] = {{1, 2}, {3, 6}, {3, 2}, {2, 2}, {1, 2}};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = CanCompleteCircuit(arr, n);
 
    (start == -1)? printf("No solution\n"): printf("Start = %d\n", start);
 
    return 0;
}
