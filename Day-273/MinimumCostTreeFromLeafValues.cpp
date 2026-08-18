class Solution {
public:
    int solveUsingTab(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int s = n-1; s >= 0; s--) {
            for(int e = 0; e < n; e++) {
                if(s >= e) continue;
                int ans = INT_MAX;
                for(int i = s; i < e; i++) {
                    int leftMax = maxi[{s, i}];
                    int rightMax = maxi[{i+1, e}];
                    int nodeValue = leftMax * rightMax;
                    ans = min(ans, nodeValue + dp[s][i] + dp[i+1][e]);
                }

                dp[s][e] = ans;
            }
        }

        
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(i == j) maxi[{i, j}] = arr[i];
                else maxi[{i, j}] = max(maxi[{i, j-1}], arr[j]);
            }
        }

        return solveUsingTab(arr, maxi);
    }
};







// class Solution {
// public:
//     int solveUsingMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int s, int e, vector<vector<int>>& dp) {
//         // base case
//         if(s >= e) return 0;

//         if(dp[s][e] != -1) return dp[s][e];

//         int ans = INT_MAX;
//         for(int i = s; i < e; i++) {
//             int leftMax = maxi[{s, i}];
//             int rightMax = maxi[{i+1, e}];
//             int nodeValue = leftMax * rightMax;
//             ans = min(ans, nodeValue + solveUsingMem(arr, maxi, s, i, dp) + solveUsingMem(arr, maxi, i+1, e, dp));
//         }

//         dp[s][e] = ans;
//         return dp[s][e];
//     }

//     int mctFromLeafValues(vector<int>& arr) {
//         map<pair<int, int>, int> maxi;
//         int n = arr.size();

//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 if(i == j) maxi[{i, j}] = arr[i];
//                 else maxi[{i, j}] = max(maxi[{i, j-1}], arr[j]);
//             }
//         }

//         int s = 0;
//         int e = n-1;
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solveUsingMem(arr, maxi, s, e, dp);
//     }
// };










// class Solution {
// public:
//     int solveUsingRec(vector<int>& arr, map<pair<int, int>, int>& maxi, int s, int e) {
//         // base case
//         if(s >= e) return 0;

//         int ans = INT_MAX;
//         for(int i = s; i < e; i++) {
//             int leftMax = maxi[{s, i}];
//             int rightMax = maxi[{i+1, e}];
//             int nodeValue = leftMax * rightMax;
//             ans = min(ans, nodeValue + solveUsingRec(arr, maxi, s, i) + solveUsingRec(arr, maxi, i+1, e));
//         }

//         return ans;
//     }

//     int mctFromLeafValues(vector<int>& arr) {
//         map<pair<int, int>, int> maxi;
//         int n = arr.size();

//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 if(i == j) maxi[{i, j}] = arr[i];
//                 else maxi[{i, j}] = max(maxi[{i, j-1}], arr[j]);
//             }
//         }

//         int s = 0;
//         int e = n-1;
//         return solveUsingRec(arr, maxi, s, e);
//     }
// };