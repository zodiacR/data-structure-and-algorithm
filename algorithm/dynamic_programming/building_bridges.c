#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) a>b?a:b

typedef struct city {
    int location;
    int idx;
}City;

int cmp(const void *a, const void *b) {
    return ((City *)a)->location - ((City *)b)->location;
}

int BuildingBridges(City *cities, int n){
    qsort(cities, n, sizeof(City), cmp);    

    int lis[n];

    for (int i = 0; i < n; i++) lis[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (cities[j].idx < cities[i].idx && lis[i] < lis[j]+1)
                lis[i] = lis[j] + 1;
        }
    }

    int max = lis[0];
    for (int i = 1; i < n; i++) max = MAX(max, lis[i]);

    return max;
}

int main() {
    City cities[] = {{0, 0}, {4, 1}, {5, 2}, {7, 3}, {8, 4}, {2, 5}, {1, 6}, {3, 7}, {9, 8}, {6, 9}};
    
    printf("Maximum non-crossing cities: %d\n", BuildingBridges(cities, 10));
}
