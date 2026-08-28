class Solution {
public:
    int solveUsingTabSO(string& s, string& t) {
        int m = s.length();
        int n = t.length();
        
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        // for(int i = 0; i <= m; i++) dp[i][n] = 1;
        next[n] = 1;
        curr[n] = 1;

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                long long int ans = 0;
                if(s[i] == t[j]) ans += next[j+1];
                ans += next[j]; 

                curr[j] = ans;
            }

            // shifting
            next = curr;
        }
        
        return next[0];
    }

    int numDistinct(string s, string t) {
        return solveUsingTabSO(s, t);
    }
};









// class Solution {
// public:
//     int solveUsingTab(string& s, string& t) {
//         int m = s.length();
//         int n = t.length();
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

//         for(int i = 0; i <= m; i++) dp[i][n] = 1;

//         for(int i = m-1; i >= 0; i--) {
//             for(int j = n-1; j >= 0; j--) {
//                 long long int ans = 0;
//                 if(s[i] == t[j]) ans += dp[i+1][j+1];
//                 ans += dp[i+1][j]; 

//                 dp[i][j] = ans;
//             }
//         }
        
//         return dp[0][0];
//     }

//     int numDistinct(string s, string t) {
//         return solveUsingTab(s, t);
//     }
// };







// class Solution {
// public:
//     int solveUsingTab(string& s, string& t) {
//         int m = s.length();
//         int n = t.length();
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

//         for(int i = 0; i <= m; i++) dp[i][n] = 1;

//         for(int i = m-1; i >= 0; i--) {
//             for(int j = n-1; j >= 0; j--) {
//                 long long int ans = 0;
//                 if(s[i] == t[j]) ans += dp[i+1][j+1];
//                 ans += dp[i+1][j]; 

//                 dp[i][j] = ans;
//             }
//         }
        
//         return dp[0][0];
//     }

//     int numDistinct(string s, string t) {
//         return solveUsingTab(s, t);
//     }
// };







// class Solution {
// public:
//     int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
//         if(j >= t.length()) return 1;
//         if(i >= s.length()) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int ans = 0;
//         if(s[i] == t[j]) ans += solveUsingMem(s, t, i+1, j+1, dp);
//         ans += solveUsingMem(s, t, i+1, j, dp);

//         dp[i][j] = ans;
//         return ans;
//     }

//     int numDistinct(string s, string t) {
//         int m = s.length();
//         int n = t.length();

//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solveUsingMem(s, t, 0, 0, dp);
//     }
// };









// class Solution {
// public:
//     int solveUsingRec(string& s, string& t, int i, int j) {
//         if(j >= t.length()) return 1;
//         if(i >= s.length()) return 0;

//         int ans = 0;
//         if(s[i] == t[j]) ans += solveUsingRec(s, t, i+1, j+1);
//         ans += solveUsingRec(s, t, i+1, j);

//         return ans;
//     }

//     int numDistinct(string s, string t) {
//         return solveUsingRec(s, t, 0, 0);
//     }
// };