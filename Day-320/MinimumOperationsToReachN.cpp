class Solution {
  public:
    int minOperation(int n) {
        int cnt = 0;
        
        while(n) {
            if(n & 1) n -= 1;
            else n /= 2;
            cnt++;
        }
        
        return cnt;
    }
};












// O(N), O(N)
// class Solution {
//   public:
//     int solveBU(int& n) {
//         vector<int> dp(n+1, INT_MAX);
//         dp[n] = 0;
        
//         for(int result = n-1; result >= 0; result--) {
//             int add = dp[result + 1];
//             if(add != INT_MAX) add += 1;
            
//             int multiply = INT_MAX;
//             if(result != 0 && (result * 2 < n+1)) {
//                 multiply = dp[result * 2];
//                 if(multiply != INT_MAX) multiply += 1;
//             }
            
//             dp[result] = min(add, multiply);
//         }
        
//         return dp[0];
//     }
  
//     int minOperation(int n) {
//         return solveBU(n);
//     }
// };












// TC - O(N), SC - O(N)
// class Solution {
//   public:
//     int solveTD(int& n, int result, vector<int>& dp) {
//         if(result == n) return 0;
//         if(result > n) return INT_MAX;
        
//         if(dp[result] != -1) return dp[result];
        
//         int add = solveTD(n, result + 1, dp);
//         if(add != INT_MAX) add += 1;
        
//         int multiply = INT_MAX;
//         if(result != 0) {
//             multiply = solveTD(n, result * 2, dp);
//             if(multiply != INT_MAX) multiply += 1;
//         }
        
//         return dp[result] = min(add, multiply);
//     }
  
//     int minOperation(int n) {
//         vector<int> dp(n+1, -1);
//         return solveTD(n, 0, dp);
//     }
// };










// Tc - O(2^n), SC - O(N)
// class Solution {
//   public:
//     int solve(int n, int result) {
//         if(result == n) return 0;
//         if(result > n) return INT_MAX;
        
//         int add = solve(n, result + 1);
//         if(add != INT_MAX) add += 1;
        
//         int multiply = INT_MAX;
//         if(result != 0) {
//             multiply = solve(n, result * 2);
//             if(multiply != INT_MAX) multiply += 1;
//         }
        
//         return min(add, multiply);
//     }
  
//     int minOperation(int n) {
//         return solve(n, 0);
//     }
// };









// class Solution {
//   public:
//     int minCnt = INT_MAX;
  
//     void solve(int n, int result, int count) {
//         if(result == n) {
//             minCnt = min(count, minCnt);
//             return;
//         }
//         if(result > n) return;
        
//         solve(n, result + 1, count + 1);
//         if(result != 0) solve(n, result * 2, count + 1);
//     }
  
//     int minOperation(int n) {
//         solve(n, 0, 0);
        
//         return minCnt;
//     }
// };