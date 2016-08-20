#include <stdio.h>
#include <stdlib.h>
#define UNASSIGNED 0
#define N 9

int IsUnassigned(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) return 1; 
        }
    }

    return 0;
}

int CheckRow(int grid[N][N], int row, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num)
            return 0;
    }
    return 1;
}

int CheckCol(int grid[N][N], int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num)
            return 0;
    }
    return 1;
}

int CheckBox(int grid[N][N], int rowStart, int colStart, int num) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if (grid[rowStart+i][colStart+j] == num) return 0;
        }
    }
    return 1;
}

int IsSafe(int grid[N][N], int row, int col, int num) {
    return CheckRow(grid, row, num) &&
               CheckCol(grid, col, num) &&
                   CheckBox(grid, row-row%3, col-col%3, num);
}

int SolveSudoku(int grid[N][N]) {
    int row, col;

    if (!IsUnassigned(grid, &row, &col))
        return 1;

    for (int i = 1; i <= N; i++) {
        if (IsSafe(grid, row, col, i)){
            grid[row][col] = i;
            if (SolveSudoku(grid)) return 1;
            grid[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

 
/* A utility function to print grid  */
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}
 
/* Driver Program to test above functions */
int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid))
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}
