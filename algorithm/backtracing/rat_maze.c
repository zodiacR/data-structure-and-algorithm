#include <stdio.h>
#include <stdlib.h>

#define N 5

int IsSafe(int x, int y, int maze[N][N]) {
    return x >= 0 && x < N &&
               y >= 0 && y < N &&
                   maze[x][y] == 1;
}

void PrintGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

int SolMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N-1 && y == N-1) {
        return 1;
    } else {
        maze[x][y] = 0;
        if (IsSafe(x, y+1, maze)){
            sol[x][y+1] = 1;
            if (SolMazeUtil(maze, x, y+1, sol)) return 1;
            sol[x][y+1] = 0;
        }
        if (IsSafe(x+1, y, maze)){
            sol[x+1][y] = 1;
            if (SolMazeUtil(maze, x+1, y, sol)) return 1;
            sol[x+1][y] = 0;
        }
        if (IsSafe(x-1, y, maze)){
            sol[x-1][y] = 1;
            if (SolMazeUtil(maze, x-1, y, sol)) return 1;
            sol[x-1][y] = 0;
        }
        maze[x][y] = 1;

        return 0;
    }
}


void SolveMaze(int maze[N][N]) {
    int sol[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            sol[i][j] = 0;
        }
    }

    sol[0][0] = 1;
    if (SolMazeUtil(maze, 0, 0, sol)){
        PrintGrid(sol);        
    } else {
        printf("No solution\n");
    }
}

// driver program to test above function
int main()
{
    int maze[N][N]  =  {
                         {1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 1, 1, 0, 1},
                         {1, 0, 1, 0, 1},
                         {0, 0, 0, 0, 1}};
 
    SolveMaze(maze);
    return 0;
}
