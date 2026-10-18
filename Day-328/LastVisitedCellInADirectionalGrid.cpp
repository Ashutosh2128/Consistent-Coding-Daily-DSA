class Solution {
public:
    int m;
    int n;
    vector<int> lastVis;

    bool isSafe(int i, int j, vector<vector<bool>>& vis) {
        return (i >= 0) && (j >= 0) && (i < m) && (j < n) && (!vis[i][j]);
    }

    void solve(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        
        if(grid[i][j] == 'L' && isSafe(i, j-1, vis)) {
            solve(grid, i, j-1, vis);
        }
        else if(grid[i][j] == 'R' && isSafe(i, j+1, vis)) {
            solve(grid, i, j+1, vis);
        }
        else if(grid[i][j] == 'U' && isSafe(i-1, j, vis)) {
            solve(grid, i-1, j, vis);
        }
        else if(grid[i][j] == 'D' && isSafe(i+1, j, vis)) {
            solve(grid, i+1, j, vis);
        }
        else {
            lastVis = {i, j};
        }
    }
    
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        solve(grid, 0, 0, vis);

        return lastVis;
    }
};