class Solution {
public:
    bool solveUsingTab(string& s, string& p, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m][n] = 1;

        for(int i = m; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                bool currMatch = (i < s.length()) && (p[j] == '.' || (s[i] == p[j]));

                bool ans;
                if(j+1 < p.length() && p[j+1] == '*') {
                    bool emptyCase = dp[i][j+2];
                    bool precidingCase = currMatch && dp[i+1][j];
                    ans = emptyCase || precidingCase;
                }
                else if(currMatch) ans = dp[i+1][j+1];
                else ans = false;

                dp[i][j] = ans;
            }
        }

        
        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        return solveUsingTab(s, p, m, n);
    }
};







// class Solution {
// public:
//     bool solveUsingMem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
//         if(i >= s.length() && j >= p.length()) return true;
//         if(j >= p.length()) return false;

//         if(dp[i][j] != -1) return dp[i][j];

//         bool currMatch = (i < s.length()) && (p[j] == '.' || (s[i] == p[j]));

//         bool ans;
//         if(j+1 < p.length() && p[j+1] == '*') {
//             bool emptyCase = solveUsingMem(s, p, i, j+2, dp);
//             bool precidingCase = currMatch && solveUsingMem(s, p, i+1, j, dp);
//             ans = emptyCase || precidingCase;
//         }
//         else if(currMatch) ans = solveUsingMem(s, p, i+1, j+1, dp);
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

//         bool currMatch = (i < s.length()) && (p[j] == '.' || (s[i] == p[j]));

//         if(j+1 < p.length() && p[j+1] == '*') {
//             bool emptyCase = solveUsingRec(s, p, i, j+2);
//             bool precidingCase = currMatch && solveUsingRec(s, p, i+1, j);
//             return emptyCase || precidingCase;
//         }
//         else if(currMatch) return solveUsingRec(s, p, i+1, j+1);
//         else return false;
//     }

//     bool isMatch(string s, string p) {
//         return solveUsingRec(s, p, 0, 0);
//     }
// };