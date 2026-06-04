#include<iostream>
using namespace std;

void print(int* arr, int n) {
    for(int i = 1; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void heapify(int* arr, int idx, int n) {
    int bigIndex = idx;
    int leftIndex = bigIndex * 2;
    int rightIndex = bigIndex * 2 + 1;

    if(leftIndex <= n && arr[bigIndex] < arr[leftIndex]) bigIndex = leftIndex;
    if(rightIndex <= n && arr[bigIndex] < arr[rightIndex]) bigIndex = rightIndex;

    if(bigIndex != idx) {
        swap(arr[bigIndex], arr[idx]);
        heapify(arr, bigIndex, n);
    }
}

void buildHeap(int* arr, int n) {
    for(int i = n/2; i > 0; i--) heapify(arr, i, n-1);
}

void heapSort(int* arr, int n) {
    while(n > 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, 1, n);
    }
}

int main() {
    int arr[9] = {-1, 10, 20, 30, 40, 50, 60, 70, 80};
    int n = 9;

    cout << "Printing heap before build: ";
    print(arr, n);

    buildHeap(arr, n);

    cout << "Printing heap after build: ";
    print(arr, n);

    heapSort(arr, n-1);

    cout << "Printing heap after heap sort: ";
    print(arr, n);

    return 0;
}