#include <iostream>
#include <cstring>
#define M 3

using namespace std;

string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary) / sizeof(dictionary[0]);

bool IsMatch(string &str) {
    for (int i = 0; i < n; i++) {
        if (str.compare(dictionary[i]) == 0)
            return true;
    }
    return false;
}

void FindWordUtil(char map[M][M], bool visited[M][M],
        int row, int col, string &str) {
    str = str + map[row][col];
    visited[row][col] = true;

    if (IsMatch(str))
        cout << str << endl;

    for (int i = row-1; i <= row+1 && i < M; i++) {
        for (int j = col-1; j <= col+1 && j < M; j++) {
            if (i>=0 && j >= 0 && !visited[i][j]) {
                FindWordUtil(map, visited, i, j, str);
            }
        }
    }

    str.erase(str.length()-1);
    visited[row][col] = false;
}

void FindWord(char map[M][M]) {
    bool visited[M][M] = {{false}};

    string str = "";

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            FindWordUtil(map, visited, i, j, str);
        }
    }
}

// Driver program to test above function
int main()
{
    char boggle[M][M] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};
 
    cout << "Following words of dictionary are present\n";
    FindWord(boggle);
    return 0;
}
