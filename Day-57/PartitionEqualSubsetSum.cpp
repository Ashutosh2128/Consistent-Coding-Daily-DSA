class Solution {
public:
    bool solve(vector<int>& nums, int halfSum, int i) {
        if(halfSum == 0) return true;
        if(halfSum < 0 || i >= nums.size()) return false;

        bool inc = solve(nums, halfSum - nums[i], i+1);
        bool exc = solve(nums, halfSum, i+1);

        return inc || exc;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1) {
            return false;
        }

        return solve(nums, sum/2, 0);
    }
};









// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);

//         if(sum & 1) {
//             return false;
//         }

//         return true;
//     }
// };






// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         if(nums.size() == 1) return false;
//         sort(nums.begin(), nums.end());

//         int i = 0;
//         int j = nums.size() - 1;

//         int left = nums[i];
//         int right = nums[j];

//         while(j-i > 1) {
//             if(left <= right) {
//                 ++i;
//                 left += nums[i];
//             }
//             else {
//                 --j;
//                 right += nums[j];
//             }
//         }

//         if(left == right) return true;
//         return false;
//     }
// };