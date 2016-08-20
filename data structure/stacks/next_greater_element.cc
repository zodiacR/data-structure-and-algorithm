#include <iostream>
#include <stack>

using namespace std;

void PrintNGE(int *arr, int n) {
    stack<int> s;

    s.push(arr[0]);

    for (int i = 1; i < n; i++){
        int top = s.top();

        while (top < arr[i]) {
            cout << top << " ---- " << arr[i] << endl;
            s.pop();
            if (s.empty()) break;

            top = s.top();
        }

        s.push(arr[i]);
    }

    while (!s.empty()) {
        int top = s.top();
        cout << top << "---- -1" << endl;
        s.pop();
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[]= {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    PrintNGE(arr, n);
    return 0;
}
