class Solution {
public:
    int maxLen = 1;
    int start = 0;

    bool solveUsingRec(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] == s[j]) flag = solveUsingRec(s, i+1, j-1, dp);
        if(flag) {
            int currLen = j - i + 1;
            if(maxLen < currLen) {
                maxLen = currLen;
                start = i;
            }
        }

        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));

        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                bool ans = solveUsingRec(s, i, j, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};