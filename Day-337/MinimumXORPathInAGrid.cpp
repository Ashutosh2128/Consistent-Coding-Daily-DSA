class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solveUsingMem(vector<vector<int>>& grid, int i, int j, int currXor) {
        if(i > m-1 || j > n-1) return INT_MAX;

        currXor ^= grid[i][j];
        if(i == m-1 && j == n-1) return currXor;

        if(dp[i][j][currXor] != -1) return dp[i][j][currXor];

        int right = solveUsingMem(grid, i, j+1, currXor);
        int down = solveUsingMem(grid, i+1, j, currXor);

        return dp[i][j][currXor] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(1025, -1))); 

        return solveUsingMem(grid, 0, 0, 0);
    }
};








// class Solution {
// public:
//     int m, n;
//     int ans = INT_MAX;

//     void solve(vector<vector<int>>& grid, int i, int j, int currXor) {
//         if(i == m-1 && j == n-1) {
//             currXor ^= grid[i][j];
//             ans = min(ans, currXor);
//             return;
//         }

//         // right call
//         if(j+1 < n) solve(grid, i, j+1, currXor ^ grid[i][j]);

//         // down call
//         if(i+1 < m) solve(grid, i+1, j, currXor ^ grid[i][j]);
//     }

//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         solve(grid, 0, 0, 0);
//         return ans;
//     }
// };