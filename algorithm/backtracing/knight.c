#include <stdio.h>
#include <stdlib.h>

#define N 8

int IsSafe(int grid[N][N], int move_x, int move_y) {
    return (move_x >= 0 && move_x < N &&
               move_y >= 0 && move_y < N &&
                   grid[move_x][move_y] == -1);
}

void PrintGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

int SolveKTUtil(int x, int y, int moves, int grid[N][N], int *moves_x, int *moves_y) {
    if (moves == N*N) return 1;

    else {
        for (int i = 0; i < 8; i++) {
            int next_move_x = x + moves_x[i];
            int next_move_y = y + moves_y[i];
            if (IsSafe(grid, next_move_x, next_move_y)) {
                grid[next_move_x][next_move_y] = moves;
                if (SolveKTUtil(next_move_x, next_move_y, moves+1, grid, moves_x, moves_y)) {
                    return 1;
                }
                grid[next_move_x][next_move_y] = -1;
            }
        }

        return 0;
    }
}

void SolveKT() {
    int grid[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = -1;
        }
    } 

    int moves_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int moves_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    /*int moves_x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };*/
    /*int moves_y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };*/

    grid[0][0] = 0;

    if (SolveKTUtil(0, 0, 1, grid, moves_x, moves_y)){
        printf("Solution exists\n");
        PrintGrid(grid);
    } else {
        printf("No solution exists\n");
    }
}

/* Driver program to test above functions */
int main()
{
    SolveKT();
    return 0;
}
