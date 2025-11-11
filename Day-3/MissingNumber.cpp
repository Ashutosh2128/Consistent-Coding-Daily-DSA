class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }

        for(int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};







//Sort and apply binary search
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int s = 0;
//         int e = nums.size() - 1;

//         int ans = -1;

//         while(s <= e) {
//             int mid = s + (e - s) / 2;

//             if(nums[mid] - mid == 1) {
//                 //may be it is answwer
//                 ans = mid;
//                 e = mid - 1;
//             }
//             else s = mid + 1;
//         }

//         return ans == -1 ? nums.size() : ans;
//     }
// };