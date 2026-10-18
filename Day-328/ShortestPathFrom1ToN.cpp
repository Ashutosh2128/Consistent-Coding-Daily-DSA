class Solution {
  public:
    int minimumStep(int n) {
        int minEdge = 0;
        
        while(n > 1) {
            if(n % 3 == 0) n /= 3;
            else n--;
            minEdge++;
        }
        
        return minEdge;
    }
};











// class Solution {
//   public:
//     int solve(int n) {
//         vector<int> dp(n+1, 0);
        
//         dp[n] = 1;
        
//         for(int i = n-1; i >= 1; i--) {
//             // sum
//             int sum = 1 + dp[i+1];
            
//             // multiply
//             int multiply = INT_MAX;
//             if(i*3 <= n) multiply = 1 + dp[i*3];
            
//             dp[i] = min(sum, multiply);
//         }
        
//         return dp[1];
//     }
  
//     int minimumStep(int n) {
//         return solve(n) - 1;
//     }
// };












// class Solution {
//   public:
//     int solve(int n, int i, vector<int>& dp) {
//         if(i > n) return 0;
//         if(i == n) return 1;
        
//         if(dp[i] != -1) return dp[i];
        
//         // sum
//         int sum = 1 + solve(n, i+1, dp);
        
//         // multiply
//         int multiply = INT_MAX;
//         if(i*3 <= n) multiply = 1 + solve(n, i*3, dp);
        
//         return dp[i] = min(sum, multiply);
//     }
  
//     int minimumStep(int n) {
//         vector<int> dp(n+1, -1);
//         return solve(n, 1, dp) - 1;
//     }
// };