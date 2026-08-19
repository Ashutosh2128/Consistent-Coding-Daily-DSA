class Solution {
public:
    bool solveUsingTabSO(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        next[n] = 1;
        for(int col = 0; col < n; col++) {
            bool flag = true;
            for(int k = col; k < p.length(); k++) {
                if(p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            next[col] = flag;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                bool ans;
                if(p[j] == '?' || s[i] == p[j]) ans = next[j+1];
                else if(p[j] == '*') ans = next[j] || curr[j+1];
                else ans = false;

                curr[j] = ans;
            }

            //shifting
            next = curr;
        }

        
        return next[0];
    }

    bool isMatch(string s, string p) {
        return solveUsingTabSO(s, p);
    }
};







// class Solution {
// public:
//     bool solveUsingTab(string& s, string& p) {
//         int m = s.length();
//         int n = p.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

//         dp[m][n] = 1;
//         for(int col = 0; col < n; col++) {
//             bool flag = true;
//             for(int k = col; k < p.length(); k++) {
//                 if(p[k] != '*') {
//                     flag = false;
//                     break;
//                 }
//             }
//             dp[m][col] = flag;
//         }

//         for(int i = m-1; i >= 0; i--) {
//             for(int j = n-1; j >= 0; j--) {
//                 bool ans;
//                 if(p[j] == '?' || s[i] == p[j]) ans = dp[i+1][j+1];
//                 else if(p[j] == '*') ans = dp[i+1][j] || dp[i][j+1];
//                 else ans = false;

//                 dp[i][j] = ans;
//             }
//         }

        
//         return dp[0][0];
//     }

//     bool isMatch(string s, string p) {
//         return solveUsingTab(s, p);
//     }
// };







// class Solution {
// public:
//     bool solveUsingMem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
//         if(i >= s.length() && j >= p.length()) return true;
//         if(j >= p.length()) return false;
//         if(i >= s.length()) {
//             for(int k = j; k < p.length(); k++) if(p[k] != '*') return false;
//             return true;
//         }

//         if(dp[i][j] != -1) return dp[i][j];

//         bool ans;
//         if(p[j] == '?' || s[i] == p[j]) ans = solveUsingMem(s, p, i+1, j+1, dp);
//         else if(p[j] == '*') ans = solveUsingMem(s, p, i+1, j, dp) || solveUsingMem(s, p, i, j+1, dp);
//         else ans = false;

//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     bool isMatch(string s, string p) {
//         int m = s.length();
//         int n = p.length();

//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solveUsingMem(s, p, 0, 0, dp);
//     }
// };








// class Solution {
// public:
//     bool solveUsingRec(string& s, string& p, int i, int j) {
//         if(i >= s.length() && j >= p.length()) return true;
//         if(j >= p.length()) return false;
//         if(i >= s.length()) {
//             for(int k = j; k < p.length(); k++) if(p[k] != '*') return false;
//             return true;
//         }

//         if(p[j] == '?' || s[i] == p[j]) return solveUsingRec(s, p, i+1, j+1);
//         else if(p[j] == '*') return solveUsingRec(s, p, i+1, j) || solveUsingRec(s, p, i, j+1);
//         else return false;
//     }

//     bool isMatch(string s, string p) {
//         return solveUsingRec(s, p, 0, 0);
//     }
// };