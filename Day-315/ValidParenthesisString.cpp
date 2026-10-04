class Solution {
public:
    bool solveUsingTab(string& s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        dp[n][0] = 1;

        for(int i = n-1; i >= 0; i--) {
            for(int count = 0; count < n; count++) {
                bool ans = false;
                if(s[i] == '(') ans = dp[i+1][count+1];
                else if(s[i] == ')' && count > 0) ans = dp[i+1][count-1];
                else if(s[i] == '*') {
                    ans = dp[i+1][count+1];
                    if(count > 0) ans = ans || dp[i+1][count-1];
                    ans = ans || dp[i+1][count];
                }

                dp[i][count] = ans;
            }
        }

        return dp[0][0];
    }

    bool checkValidString(string s) {
        return solveUsingTab(s);
    }
};








// class Solution {
// public:
//     bool solve(string s, int i, int count, vector<vector<int>>& dp) {
//         if(i >= s.length() && count == 0) return true;
//         if(count < 0) return false;
//         if(i >= s.length()) return false;

//         if(dp[i][count] != -1) return dp[i][count];

//         bool ans = false;
//         if(s[i] == '(') ans = ans || solve(s, i+1, count+1, dp);
//         else if(s[i] == ')') ans = ans || solve(s, i+1, count-1, dp);
//         else if(s[i] == '*') ans = ans || solve(s, i+1, count+1, dp) || solve(s, i+1, count-1, dp) || solve(s, i+1, count, dp);

//         return dp[i][count] = ans;
//     }

//     bool checkValidString(string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(s, 0, 0, dp);
//     }
// };