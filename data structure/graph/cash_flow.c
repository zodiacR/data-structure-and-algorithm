#include <stdio.h>
#include <stdlib.h>
#define N 3

int getMax(int amount[]) {
    int maxIdx = 0;

    for (int i = 1 ; i < N; i++) {
        if (amount[i] > amount[maxIdx]) maxIdx = i;
    }

    return maxIdx;
}

int getMin(int amount[]) {
    int minIdx = 0;

    for (int i = 1 ; i < N; i++) {
        if (amount[i] < amount[minIdx]) minIdx = i;
    }

    return minIdx;
}

int minOf2(int x, int y) {
    return x<y? x:y;
}

void CashFlowRed(int amount[]) {
    int credMax = getMax(amount);
    int debMax = getMin(amount);

    if (!amount[credMax] && !amount[debMax]) return;

    int min = minOf2(-amount[debMax], amount[credMax]);

    amount[credMax] -= min;
    amount[debMax] += min;

    printf("Person %d pays %d to persion %d\n", debMax, min, credMax);

    CashFlowRed(amount);
}

void MinCashFlow(int graph[N][N]) {
    int amount[N] = {0};

    for (int i = 0; i < N; i++) {
        for (int p = 0; p < N; p++) {
            amount[i] += graph[p][i] - graph[i][p];
        }
    }

    CashFlowRed(amount);
}

// Driver program to test above function
int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    // Print the solution
    MinCashFlow(graph);
    return 0;
}

