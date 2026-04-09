#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int sumOfMinAndMax(vector<int>& arr, int k) {
    deque<int> max, min;
    int ans = 0;

    //process first window
    for(int i = 0; i < k; i++) {
        while(!max.empty() && arr[max.back()] < arr[i]) max.pop_back();
        max.push_back(i);

        while(!min.empty() && arr[min.back()] > arr[i]) min.pop_back();
        min.push_back(i);
    }

    //process remaining window
    for(int i = k; i < arr.size(); i++) {
        //step-1: find answer
        ans += arr[max.front()] + arr[min.front()];

        //step-2: deletion
        if(i - max.front() == k) max.pop_front();
        if(i - min.front() == k) min.pop_front();

        //step-3: adding
        while(!max.empty() && arr[max.back()] < arr[i]) max.pop_back();
        max.push_back(i);

        while(!min.empty() && arr[min.back()] > arr[i]) min.pop_back();
        min.push_back(i);
    }

    ans += arr[max.front()] + arr[min.front()];

    return ans;
}

int main() {
    vector<int> arr = {2, -3, 4, -2, -7, 6, 8};
    int k = 3;

    cout << sumOfMinAndMax(arr, k) << endl;

    return 0;
}