#include <iostream>
using namespace std;

bool isPresent(int arr[], int n, int key, int idx) {
    if(idx >= n) return false;

    if(arr[idx] == key) return true;
    else isPresent(arr, n, key, idx+1);
}

int main() {
    int arr[7] = {5, 3, 1, 2, 7, 8, 6};
    int key = 5;

    if(isPresent(arr, 7, key, 0)) {
        cout << key << " is present in the array" << endl;
    }
    else {
        cout << key << " is not present in the array" << endl;
    }

    return 0;
}