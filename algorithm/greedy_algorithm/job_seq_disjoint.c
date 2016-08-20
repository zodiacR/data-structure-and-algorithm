#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MIN(a,b) a<b?a:b

typedef struct job {
    char id;
    int deadline;
    int profit;
}Job;

int cmp(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int Find(int *parent, int v) {
    if (parent[v] != v) {
        parent[v] = Find(parent, parent[v]);
    }

    return parent[v];
}

void Union(int *parent, int v, int u) {
    parent[u] = v;
}

int MaxDeadline(Job *jobs, int n) {
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (max < jobs[i].deadline){
            max = jobs[i].deadline;
        }
    }

    return max;
}

void PrintJobSchedule(Job *jobs, int n) {
    qsort(jobs, n, sizeof(Job), cmp);

    int max_deadline = MaxDeadline(jobs, n);

    int *parent = (int *)malloc(sizeof(int)*(max_deadline+1));

    for (int i = 0; i <= max_deadline; i++) parent[i] = i;

    for (int i = 0; i < n; i++) {
        int available = Find(parent, jobs[i].deadline);
        
        if (available > 0) {
            printf("%c ", jobs[i].id);
            Union(parent, Find(parent, available-1), available);
        }
    }

    printf("\n");
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
