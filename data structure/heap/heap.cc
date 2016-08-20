#include <iostream>
#include "heap.h"
using namespace std;

int main(){
    MinHeap h(11);
    h.InsertKey(3);
    h.InsertKey(2);
    h.DeleteKey(1);
    h.InsertKey(15);
    h.InsertKey(5);
    h.InsertKey(4);
    h.InsertKey(45);
    cout << h.ExtractMin() << " ";
    cout << h.GetMin() << " ";
    h.DecreaseKey(2, 1);
    cout << h.GetMin() << endl;
    return 0;
}
