#include<iostream>
using namespace std;

void findMaximum(int* arr, int n, int& maxi, int idx) {
    if(idx >= n) return;

    if(arr[idx] > maxi) maxi = arr[idx];

    findMaximum(arr, n, maxi, idx+1);
}

void findMinimum(int* arr, int n, int& mini, int idx) {
    if(idx >= n) return;

    if(arr[idx] < mini) mini = arr[idx];

    findMinimum(arr, n, mini, idx+1);
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 10, 8, 6, 4, 2};
    int maxi = -1000;
    int mini = 1000;

    findMaximum(arr, 10, maxi, 0);
    findMinimum(arr, 10, mini, 0);

    cout << "Maximum element in the array is: " << maxi << endl;
    cout << "Minimum element in the array is: " << mini << endl;

    return 0;
}