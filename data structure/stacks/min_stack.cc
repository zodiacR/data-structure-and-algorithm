#include <stack>
#include <iostream>
#include <climits>
using namespace std;


class Stack{
    private:
        stack<int> s;
        int min;
    public:
        int Pop();
        void Push(int x);
        int Top();
        int Min();
};

int Stack::Pop() {
    if (s.empty()) return -1;
    else {
        int top = s.top();
        if (top < min){
            int tmp = min;
            min = 2*min - top;
            top = tmp;
        }
        s.pop();

        return top;
    } 
}

void Stack::Push(int x) {
    if (s.empty()) min = x;
    if (x < min) {
        int tmp = 2*x - min;
        min = x;
        s.push(tmp);
    } else {
        s.push(x);
    }
}

int Stack::Top() {
    if (s.empty()) return INT_MIN;
    int top = s.top();

    if (top < min) {
        return min;
    } else {
        return top;
    }
}

int Stack::Min(){
    if (s.empty()) return INT_MIN;
    return min;
}

int main() {
    int arr[] = {81, 16, 97, 94, 2, 38, 6, 89};
    int n = sizeof(arr) / sizeof(arr[0]);

    Stack s = Stack();

    for (int i = 0; i < n; i++) {
        s.Push(arr[i]);
        cout << "Min: " << s.Min() << endl;
    }

    for (int i = 0; i < n+1; i++) {
        cout << s.Pop() << endl;
    }
}
