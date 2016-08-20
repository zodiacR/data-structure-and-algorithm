#include <iostream>
#include <stack>

using namespace std;

void InsertAtBottom(stack<int> &s, int item) {
    if (s.empty()) {
        s.push(item);
    } else {
        int tmp = s.top();
        s.pop();
        InsertAtBottom(s, item);
        s.push(tmp);
    }
}

void Reverse(stack<int> &s) {
    if (!s.empty()) {
        int tmp = s.top();
        s.pop();
        Reverse(s);
        InsertAtBottom(s, tmp);
    }
}

void PrintStack(stack<int> s) {
    if (!s.empty()) {
        int tmp = s.top();
        cout << tmp << " ";
        s.pop();
        PrintStack(s);
        s.push(tmp);
    }
}

int main() {
    stack<int> s;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    cout << "Before: ";
    PrintStack(s);
    cout << endl;

    Reverse(s);

    cout << "After: ";
    PrintStack(s);
    cout << endl;

    return 0;
}
