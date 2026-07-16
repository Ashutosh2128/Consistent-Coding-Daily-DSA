class Solution {
public:
    int solveUsingMem(vector<int>& arr, int lastIdx, int idx, vector<vector<int>>& dp) {
        if(idx >= arr.size()) return 0;

        //step-3: after base case check it is alredy exist in dp array or not
        if(dp[lastIdx+1][idx] != -1) return dp[lastIdx+1][idx];

        int inc = 0;
        if(lastIdx == -1 || arr[idx] > arr[lastIdx]) inc = 1 + solveUsingMem(arr, idx, idx+1, dp);
        int exc = solveUsingMem(arr, lastIdx, idx+1, dp);

        //step-2: store ans in dp array and return
        dp[lastIdx+1][idx] = max(inc, exc);
        return dp[lastIdx+1][idx];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // step-1: create dp array and pass it into the function
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveUsingMem(nums, -1, 0, dp);
    }
};




// class Solution {
// public:
//     int solve(vector<int>& arr, int lastIdx, int idx) {
//         if(idx >= arr.size()) return 0;

//         int inc = 0;
//         if(lastIdx == -1 || arr[idx] > arr[lastIdx]) inc = 1 + solve(arr, idx, idx+1);
//         int exc = solve(arr, lastIdx, idx+1);

//         return max(inc, exc);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return solve(nums, -1, 0);
//     }
// };