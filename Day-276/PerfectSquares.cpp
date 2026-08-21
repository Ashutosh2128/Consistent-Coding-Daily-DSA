class Solution {
public:
    int solveUsingTab(int n) {
        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; i++) {
            int st = 1;
            int end = sqrt(i);

            int ans = INT_MAX;
            while(st <= end) {
                int perfectSquare = st * st;
                int recAns = 1 + dp[i-perfectSquare];
                if(recAns < ans) ans = recAns;
                st++;
            }

            dp[i] = ans;
        }

        
        return dp[n];
    }

    int numSquares(int n) {
        return solveUsingTab(n);
    }
};






// class Solution {
// public:
//     int solveUsingMem(int n, vector<int>& dp) {
//         if(n == 0) return 0;
//         // if(n < 0) return 0;

//         if(dp[n] != -1) return dp[n];

//         int st = 1;
//         int end = sqrt(n);

//         int ans = INT_MAX;
//         while(st <= end) {
//             int perfectSquare = st * st;
//             int recAns = 1 + solveUsingMem(n-perfectSquare, dp);
//             if(recAns < ans) ans = recAns;
//             st++;
//         }

//         dp[n] = ans;
//         return dp[n];
//     }

//     int numSquares(int n) {
//         vector<int> dp(n+1, -1);
//         return solveUsingMem(n, dp);
//     }
// };








// class Solution {
// public:
//     int solveUsingRec(int n) {
//         if(n == 0) return 0;

//         int st = 1;
//         int end = sqrt(n);

//         int ans = INT_MAX;
//         while(st <= end) {
//             int perfectSquare = st * st;
//             int recAns = 1 + solveUsingRec(n-perfectSquare);
//             if(recAns < ans) ans = recAns;
//             st++;
//         }

//         return ans;
//     }

//     int numSquares(int n) {
//         return solveUsingRec(n);
//     }
// };