#include <iostream>
#include <unordered_set>
#define N(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int DuplicateK(int *arr, int k, int n){
    unordered_set<int> table;
    int bound = 0;

    for (int i = 0; i < k; i++)
        table.insert(arr[i]);

    for (int i = k; i < n; i++){
        unordered_set<int>::const_iterator it = table.find(arr[i]);
        if (it != table.cend()) return 1;
        table.erase(arr[bound]);
        bound++;
        table.insert(arr[i]);
    }

    return 0;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
    int k = 3;
    if (DuplicateK(arr, k , N(arr)))
        cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}
