class Solution {
public:
    int solveUsingTab(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m-1; i >= 0; i--) dp[i][n] = s1[i] + dp[i+1][n];
        for(int i = n-1; i >= 0; i--) dp[m][i] = s2[i] + dp[m][i+1];

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int cost = 0;
                if(s1[i] == s2[j]) cost = dp[i + 1][j + 1];
                else {
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }

                dp[i][j] = cost;
            }
        }
        
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        return solveUsingTab(s1, s2);
    }
};






// class Solution {
// public:
//     int solveUsingMem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
//         int cost = 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(i == s1.size() || j == s2.size()) {
//             for(int k = i; k < s1.size(); k++) cost += s1[k];
//             for(int k = j; k < s2.size(); k++) cost += s2[k];
//         }
//         else if(s1[i] == s2[j]) cost = solveUsingMem(s1, s2, i + 1, j + 1, dp);
//         else {
//             int cost1 = s1[i] + solveUsingMem(s1, s2, i + 1, j, dp);
//             int cost2 = s2[j] + solveUsingMem(s1, s2, i, j + 1, dp);
//             cost = min(cost1, cost2);
//         }

//         dp[i][j] = cost;
//         return dp[i][j];
//     }

//     int minimumDeleteSum(string s1, string s2) {
//         int m = s1.length();
//         int n = s2.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solveUsingMem(s1, s2, 0, 0, dp);
//     }
// };








// class Solution {
// public:
//     int solveUsingRec(string& s1, string& s2, int i, int j) {
//         int cost = 0;

//         if(i == s1.size() || j == s2.size()) {
//             for(int k = i; k < s1.size(); k++) cost += s1[k];
//             for(int k = j; k < s2.size(); k++) cost += s2[k];
//         }
//         else if(s1[i] == s2[j]) cost = solveUsingRec(s1, s2, i + 1, j + 1);
//         else {
//             int cost1 = s1[i] + solveUsingRec(s1, s2, i + 1, j);
//             int cost2 = s2[j] + solveUsingRec(s1, s2, i, j + 1);
//             cost = min(cost1, cost2);
//         }

//         return cost;
//     }

//     int minimumDeleteSum(string s1, string s2) {
//         return solveUsingRec(s1, s2, 0, 0);
//     }
// };