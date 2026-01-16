#include <bits/stdc++.h> 

int partition(vector<int>& arr, int s, int e) {
    int pivot = arr[s];

    int count = 0;
    for(int i = s + 1; i <= e; i++) {
        if(arr[i] <= pivot) count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    //Now all the left from pivotIndex is smaller and right are greater
    int i = s;
    int j = e;
    while(i < j) {
        if(arr[i] <= arr[pivotIndex]) i++;
        else if(arr[j] > arr[pivotIndex]) j--;
        else swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSortHelper(vector<int>& arr, int s, int e) {
    if(s >= e) return;

    int p = partition(arr, s, e);

    quickSortHelper(arr, s, p-1);
    quickSortHelper(arr, p+1, e);
}

vector<int> quickSort(vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size()-1);
    return arr;
}
