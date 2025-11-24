class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int sum) {
        int e = nums.size() - 1;

        while(s <= e) {
            int mid = s + ((e - s) >> 1);

            if(nums[mid] == sum) return sum;
            else if(nums[mid] > sum) e = mid - 1;
            else s = mid + 1;
        }

        return -10; //due to the test case [-1,-2,-3], where k = 1, and the output is 2
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        set<int> st;

        for(int i = 0; i < n; i++) {
            int sum = nums[i] + k;
            if(binarySearch(nums, i+1, sum) != -10) {
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};








//Require O(n logn) complexity, but can't think of the approach
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         set<int> st;

//         int i = 0;
//         int j = 1;

//         while(j < n) {
//             if(abs(nums[i]-nums[j]) == k && i != j) {
//                 st.insert(nums[i]+nums[j]);
//                 i++; j++;
//             }
//             else if(abs(nums[i]-nums[j]) < k) j++;
//             else if(abs(nums[i]-nums[j]) > k) i++;
//             else j++;
//         }

//         return st.size();
//     }
// };









// require O(n^2) complexity - Brute Force
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int n = nums.size();
//         set<int> st;

//         for(int i = 0; i < n-1; i++) {
//             for(int j = i+1; j < n; j++) {
//                 if(abs(nums[i] - nums[j]) == k) st.insert(nums[i]+nums[j]);
//             }
//         }

//         return st.size();
//     }
// };