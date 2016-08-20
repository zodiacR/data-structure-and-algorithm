#include <iostream>
#include <stack>

using namespace std;

void Insert(stack<int> &s, int item) {
    if (s.empty() || s.top() < item) {
        s.push(item);
    } else {
        int tmp = s.top();
        s.pop();
        Insert(s, item);
        s.push(tmp);
    }
}

void Sort(stack<int> &s) {
    if (!s.empty()) {
        int tmp = s.top();
        s.pop();
        Sort(s);
        Insert(s, tmp);
    }
}

void PrintStack(stack<int> s) {
    if (!s.empty()) {
        int top = s.top();
        cout << top << " ";
        s.pop();
        PrintStack(s);
        s.push(top);
    }
}

int main(void)
{
    stack<int> s;
 
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
 
    cout << "Stack elements before sorting:\n";
    PrintStack(s);
    cout << endl;
 
    Sort(s);
 
    cout << "Stack elements after sorting:\n";
    PrintStack(s);
 
    return 0;
}
