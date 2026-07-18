class Solution {
  public:
    int solveUsingMem(vector<int>& val, vector<int>& wt, int capacity, int i, vector<vector<int>>& dp) {
        if(i >= val.size()) return 0;
        
        // step-3: after vase case check wheather ans present in dp array or not
        if(dp[capacity][i] != -1) return dp[capacity][i];
        
        int inc = 0;
        if(wt[i] <= capacity) inc = val[i] + solveUsingMem(val, wt, capacity - wt[i], i+1, dp);
        int exc = solveUsingMem(val, wt, capacity, i+1, dp);
        
        //step-2: store ans and return through dp array
        dp[capacity][i] = max(inc, exc);
        return dp[capacity][i];
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int i = 0;
        int n = val.size();
        // step-1: create a dp array and pass it into the function
        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        return solveUsingMem(val, wt, W, i, dp);
    }
};






// class Solution {
//   public:
//     int solve(vector<int>& val, vector<int>& wt, int capacity, int i) {
//         if(i >= val.size()) return 0;
        
//         int inc = 0;
//         if(wt[i] <= capacity) inc = val[i] + solve(val, wt, capacity - wt[i], i+1);
//         int exc = solve(val, wt, capacity, i+1);
        
//         return max(inc, exc);
//     }
  
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         int i = 0;
//         return solve(val, wt, W, i);
//     }
// };