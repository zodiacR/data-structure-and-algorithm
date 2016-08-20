#include <stdlib.h>
#include <stdio.h>

#define MIN(a,b) a<b?a:b

typedef struct job {
    char id;
    int deadline;
    int profit;
}Job;

int cmp(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void PrintJobSchedule(Job *jobs, int n) {
    qsort(jobs, n, sizeof(Job), cmp);
    for (int i = 0; i < n; i++)
        printf("%c %d\n", jobs[i].id, jobs[i].profit);

    int *occupied = (int *)malloc(sizeof(int) * n);
    int *results = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) occupied[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = MIN(n, jobs[i].deadline)-1; j >= 0; j--) {
            if (!occupied[j]) {
                results[j] = i;
                occupied[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (occupied[i]) {
            printf("%c ", jobs[results[i]].id);
        }
    }
    printf("\n");

    free(occupied);
    free(results);
}
// Driver program to test methods
int main()
{
    /*Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},*/
                   /*{'d', 1, 25}, {'e', 3, 15}};*/
    
    Job arr[] = { {'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40},
                   {'e', 1, 30}, {'d', 3, 20}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Following is maximum profit sequence of jobs\n");
    PrintJobSchedule(arr, n);
    return 0;
}
