class Solution {
public:
    bool solveUsingTabSO2(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> curr(target+1, 0);
        // vector<int> next(target+1, 0);

        for(int col = 0; col < n+1; col++) curr[0] = 1;

        for(int i = nums.size()-1; i >= 0; i--) {
            for(int t = target; t >= 0; t--) {
                bool inc = 0;
                if(t-nums[i] >= 0) inc = curr[t-nums[i]];
                bool exc = curr[t];

                curr[t] = inc || exc;
            }

            // next = curr;
        }
        
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;

        
        return solveUsingTabSO2(nums, sum/2);
    }
};






// class Solution {
// public:
//     bool solveUsingTabSO(vector<int>& nums, int target) {
//         int n = nums.size();

//         vector<int> curr(target+1, 0);
//         vector<int> next(target+1, 0);

//         for(int col = 0; col < n+1; col++) next[0] = 1;

//         for(int i = nums.size()-1; i >= 0; i--) {
//             for(int t = 1; t <= target; t++) {
//                 bool inc = 0;
//                 if(t-nums[i] >= 0) inc = next[t-nums[i]];
//                 bool exc = next[t];

//                 curr[t] = inc || exc;
//             }

//             next = curr;
//         }
        
//         return next[target];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum & 1) return false;

        
//         return solveUsingTabSO(nums, sum/2);
//     }
// };







// class Solution {
// public:
//     bool solveUsingTab(vector<int>& nums, int target) {
//         // step-1: create a dp array
//         vector<vector<bool>> dp(target+1, vector<bool>(nums.size()+1, 0));

//         //step-2: analyse base case and update dp array
//         for(int col = 0; col < nums.size()+1; col++) dp[0][col] = 1;

//         //step-3: reverse it then copy paste logic
//         for(int t = 1; t <= target; t++) {
//             for(int i = nums.size()-1; i >= 0; i--) {
//                 // copy paste logic
//                 bool inc = 0;
//                 if(t-nums[i] >= 0) inc = dp[t-nums[i]][i+1];
//                 bool exc = dp[t][i+1];

//                 dp[t][i] = inc || exc;
//             }
//         }
        
//         return dp[target][0];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum & 1) return false;

        
//         return solveUsingTab(nums, sum/2);
//     }
// };









// class Solution {
// public:
//     bool solveUsingMem(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
//         if(target == 0) return true;
//         if(target < 0 || i >= nums.size()) return false;

//         //step-3: after base case check wheather ans exist in dp array or not
//         if(dp[target][i] != -1) return dp[target][i];

//         bool inc = solveUsingMem(nums, target-nums[i], i+1, dp);
//         bool exc = solveUsingMem(nums, target, i+1, dp);

//         //step-2: store and in dp array and return;
//         dp[target][i] = inc || exc;
//         return dp[target][i];
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum & 1) return false;

//         // step-1: create a dp array and pass it into the function
//         vector<vector<int>> dp(sum/2+1, vector<int>(nums.size()+1, -1));
//         return solveUsingMem(nums, sum/2, 0, dp);
//     }
// };






// class Solution {
// public:
//     bool solveUsingRec(vector<int>& nums, int target, int i) {
//         if(target == 0) return true;
//         if(target < 0 || i >= nums.size()) return false;

//         bool inc = solveUsingRec(nums, target-nums[i], i+1);
//         bool exc = solveUsingRec(nums, target, i+1);

//         return inc || exc;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum & 1) return false;

//         return solveUsingRec(nums, sum/2, 0);
//     }
// };