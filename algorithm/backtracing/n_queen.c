#include <stdio.h>
#include <stdlib.h>
#define N 4

int IsSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return 0;
    }

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--)
        if (board[i][j]) return 0;

    for (int i = row+1, j=col-1; i<N && j >=0; i++, j--)
        if (board[i][j]) return 0;

    return 1;
}

int SolveNQ(int board[N][N], int col) {
    if (col >= N) return 1;

    for (int i = 0; i < N; i++) {
        if (IsSafe(board, i, col)) {
            board[i][col] = 1;
            if (SolveNQ(board, col+1)) return 1;
            board[i][col] = 0;
        }
    }

    return 0;
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( SolveNQ(board, 0) == 0 )
    {
      printf("Solution does not exist");
    }
 
    printSolution(board);
}
 
