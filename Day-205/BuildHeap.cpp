#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i = 1; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void heapify(int arr[], int idx, int n) {
    int bigIndex = idx;
    int leftIndex = bigIndex * 2;
    int rightIndex = bigIndex * 2 + 1;

    if(leftIndex <= n && arr[bigIndex] < arr[leftIndex]) bigIndex = leftIndex;
    if(rightIndex <= n && arr[bigIndex] < arr[rightIndex]) bigIndex = rightIndex;

    if(bigIndex != idx) {
        swap(arr[idx], arr[bigIndex]);
        heapify(arr, bigIndex, n);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2; i > 0; i--) heapify(arr, i, n-1);
}

int main() {
    int arr[8] = {-1, 10, 20, 30, 40, 50, 60, 70};
    int n = 8;

    cout << "Printing heap before build: ";
    print(arr, 8);

    buildHeap(arr, n);

    cout << "Printing heap after build: ";
    print(arr, 8);

    return 0;
}