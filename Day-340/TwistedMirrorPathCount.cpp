class Solution {
public:
    int mod = 1000000007;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int dir, int m, int n) {
        // out of bound
        if(i >= m || j >= n) return 0;

        // reach at the right-buttom
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];

        if(grid[i][j] == 1) {
            if(dir == 0) {
                ++i;
                dir = 1;
            } else {
                ++j;
                dir = 0;
            }

            return solve(grid, i, j, dir, m, n);
        }

        int ans = 0;

        // right move
        ans += solve(grid, i, j+1, 0, m, n);

        // down move
        ans += solve(grid, i+1, j, 1, m, n);

        return dp[i][j][dir] = ans % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<vector<int>>>(m+1, vector<vector<int>>(n+1, vector<int>(3, -1)));

        return solve(grid, 0, 0, 0, m, n);
    }
};