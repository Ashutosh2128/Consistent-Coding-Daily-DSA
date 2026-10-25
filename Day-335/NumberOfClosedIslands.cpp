class Solution {
public:
    int m;
    int n;

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if(grid[i][j]) return true;

        // mark as visited
        grid[i][j] = 1;

        bool left = dfs(grid, i, j-1);
        bool up = dfs(grid, i-1, j);
        bool right = dfs(grid, i, j+1);
        bool down = dfs(grid, i+1, j);

        return left && up && right && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int colsedIslands = 0;

        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 0) 
                    if(dfs(grid, i, j)) colsedIslands++;
            
        return colsedIslands;
    }
};