class Solution {
  public:
    int solveUsingTabSO(int n, int k) {
        int prev2 = k;
        int prev1 = k + k * (k-1);
        
        if(n == 1) return prev2;
        if(n == 2) return prev1;
        
        for(int i = 3; i <= n; i++) {
            int curr = (k-1) * (prev2 + prev1);
            
            //shifting
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
  
    int countWays(int n, int k) {
        return solveUsingTabSO(n, k);
    }
};








// class Solution {
//   public:
//     int solveUnsingTab(int n, int k) {
//         // step-1: create a dp array
//         vector<int> dp(n+1, -1);
        
//         // step-2: analyse base case and update dp array
//         dp[1] = k;
//         dp[2] = k + k * (k-1);
        
        
        
//         // step-3: reverse it and copy paste logic
//         for(int i = 3; i <= n; i++) {
//             dp[i] = (k-1) * (dp[i-2] + dp[i-1]);
//         }
        
//         return dp[n];
//     }
  
//     int countWays(int n, int k) {
//         return solveUnsingTab(n, k);
//     }
// };









// class Solution {
//   public:
//     int solveUnsingMem(int n, int k, vector<int>& dp) {
//         if(n == 1) return k;
//         if(n == 2) return k + k * (k-1);
        
//         // step-3: after base case check if answer already exist or not in dp array.
//         if(dp[n] != -1) return dp[n];
        
//         // step-2: store ans in dp array and return 
//         dp[n] = (k-1) * (solveUnsingMem(n-2, k, dp) + solveUnsingMem(n-1, k, dp));
//         return dp[n];   
//     }
  
//     int countWays(int n, int k) {
//         // step-1: create dp array and pass it to function
//         vector<int> dp(n+1, -1);
//         return solveUnsingMem(n, k, dp);
//     }
// };








// class Solution {
//   public:
//     int solve(int n, int k) {
//         if(n == 1) return k;
//         if(n == 2) return k + k * (k-1);
        
//         return (k-1) * (solve(n-2, k) + solve(n-1, k));
//     }
  
//     int countWays(int n, int k) {
//         return solve(n, k);
//     }
// };