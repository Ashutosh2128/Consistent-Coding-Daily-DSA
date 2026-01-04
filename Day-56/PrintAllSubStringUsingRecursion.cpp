#include<iostream>
#include<vector>
using namespace std;

void printSubArray(vector<int>& arr, int i, int j) {
    //base case - 1
    if(i == arr.size()) return;

    //base case - 2
    if(j == arr.size()) {
        i += 1;
        j = i;
        if(i < arr.size())
            printSubArray(arr, i, j);
        return;
    }

    for(int start = i; start <= j; start++) {
        cout << arr[start] << " ";
    } cout << endl;

    printSubArray(arr, i, j+1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    printSubArray(arr, 0, 0);

    return 0;
}