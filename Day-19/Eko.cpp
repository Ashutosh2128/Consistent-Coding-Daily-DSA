#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int require, int height) {
    long long int maxHeight = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > height) {
            maxHeight += arr[i] - height;
        }
    }

    return maxHeight >= require;
}

int maxSawbladeHeight(vector<int>& arr, int require) {
    long long int s = 0;
    long long int e = *max_element(arr.begin(), arr.end());

    long long int ans = -1;

    while(s <= e) {
        long long int mid = s + (e - s) / 2;

        if(isPossible(arr, require, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> treesHeight;

    for(int i = 0; i < n; i++) {
        int height;
        cin >> height;
        treesHeight.push_back(height);
    }

    cout << maxSawbladeHeight(treesHeight, m) << endl;

    return 0;
}