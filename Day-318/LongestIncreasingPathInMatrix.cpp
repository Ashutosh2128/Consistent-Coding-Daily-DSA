class Solution {
  public:
    vector<vector<int>> direction = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    bool isValid(int& x, int& y, int& n, int& m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
  
    int solve(vector<vector<int>> &matrix, int& n, int& m, int x, int y, vector<vector<int>>& dp) {
        // if(x >= n && y >= m) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int ans = 1;
        for(vector<int>& dir : direction) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            
            if(isValid(newX, newY, n, m) && matrix[x][y] < matrix[newX][newY])
                ans = max(ans, 1 + solve(matrix, n, m, newX, newY, dp));
        }
        
        return dp[x][y] = ans;
    }
  
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(matrix, n, m, i, j, dp));
            }
        }
        
        return ans;
    }
};