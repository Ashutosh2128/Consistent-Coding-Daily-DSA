class Solution {
public:
    long long int mod = 1000000007;

    int solveUsingTabSO(int n, int k, int target) {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int N = 1; N <= n; N++) {
            for(int t = 1; t <= target; t++) {
                long long int ans = 0;
                for(int i = 1; i <= k; i++) {
                    if(t-i >= 0) ans += prev[t-i];
                }

                curr[t] = ans % mod;
            }

            prev = curr;
        }

        return curr[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        return solveUsingTabSO(n, k, target);
    }
};











// class Solution {
// public:
//     long long int mod = 1000000007;

//     int solveUsingTab(int n, int k, int target) {
//         vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, 0));

//         dp[0][0] = 1;

//         for(int N = 1; N <= n; N++) {
//             for(int t = 1; t <= target; t++) {
//                 long long int ans = 0;
//                 for(int i = 1; i <= k; i++) {
//                     if(t-i >= 0) ans += dp[N-1][t-i];
//                 }

//                 dp[N][t] = ans % mod;
//             }
//         }

//         return dp[n][target];
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         return solveUsingTab(n, k, target);
//     }
// };










// class Solution {
// public:
//     long long int mod = 1000000007;

//     int solveUsingMem(int n, int k, int target, vector<vector<long long int>>& dp) {
//         if(n < 0 || target < 0) return 0;
//         if(n != 0 && target == 0) return 0;
//         if(n == 0 && target != 0) return 0;
//         if(n == 0 && target == 0) return 1;

//         if(dp[n][target] != -1) return dp[n][target];

//         long long int ans = 0;
//         for(int i = 1; i <= k; i++) ans += solveUsingMem(n-1, k, target-i, dp);

//         dp[n][target] = ans % mod;
//         return dp[n][target];
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
//         return solveUsingMem(n, k, target, dp);
//     }
// };









// class Solution {
// public:
//     long long int mod = 1000000007;

//     int solveUsingRec(int n, int k, int target) {
//         if(n < 0 || target < 0) return 0;
//         if(n != 0 && target == 0) return 0;
//         if(n == 0 && target != 0) return 0;
//         if(n == 0 && target == 0) return 1;

//         long long int ans = 0;
//         for(int i = 0; i <= k; i++) ans += solveUsingRec(n-1, k, target-i);

//         return ans % mod;
//     }

//     int numRollsToTarget(int n, int k, int target) {
//         return solveUsingRec(n, k, target);
//     }
// };