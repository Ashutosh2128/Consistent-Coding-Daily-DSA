.class Solution {
public:
    int binarySearch(vector<int>& arr, int x) {
        int s = 0;
        int e = arr.size() - 1;

        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(arr[mid] == x) return mid;
            else if(arr[mid] > x) {
                ans = mid;
                e = mid - 1;
            }
            else if(arr[mid] < x) {
                s = mid + 1;
            }
        }

        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int e = binarySearch(arr, x);
        if(e == -1) return vector<int>(arr.end() - k, arr.end());
        int s = e-1;

        while(k--) {
            if(s < 0) e++;
            else if(e > arr.size() - 1) s--;
            else if(x-arr[s] <= arr[e]-x) s--;
            else e++;
        }

        return vector<int>(arr.begin() + s + 1, arr.begin() + e);
    }
};







// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int s = 0;
//         int e = arr.size() - 1;

//         while((e-s) >= k) {
//             if(x - arr[s] > arr[e] - x) s++;
//             else e--;
//         }

//         return vector<int>(arr.begin()+s, arr.begin()+e+1);
//     }
// };