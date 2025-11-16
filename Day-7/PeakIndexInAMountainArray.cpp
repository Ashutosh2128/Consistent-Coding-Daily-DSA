class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        int ans = -1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(arr[mid+1] > arr[mid]) s = mid + 1;
            else {
                ans = mid;
                e = mid;
            }
        }

        return ans;
    }
};





// Require O(n) complexity
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         for(int i = 0; i < arr.size(); i++) {
//             if((i + 1 < arr.size()) && arr[i + 1] < arr[i]) return i;
//         }

//         return -1;
//     }
// };