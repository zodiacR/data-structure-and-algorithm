#include <iostream>
#include <stack>

using namespace std;

void StockSpan(int *arr, int n) {
    int *span = new int[n];
    stack<int> s;

    span[0] = 1;
    s.push(0);

    for (int i = 1; i < n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop(); 
        }    

        span[i] = s.empty()? i+1:i-s.top();
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl; 

    delete [] span;
}

// Driver program to test above function
int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    // Fill the span values in array S[]
    StockSpan(price, n);
 
    return 0;
}
