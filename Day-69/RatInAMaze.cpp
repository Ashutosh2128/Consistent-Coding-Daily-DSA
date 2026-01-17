class Solution {
  public:
    bool isSafe(vector<vector<int>>& maze, vector<vector<bool>>& visited, int n, int row, int col) {
        if((row < 0 || row >= n) || (col < 0 || col >= n) || (maze[row][col] == 0) || (visited[row][col] == true))
            return false;
            
        return true;
    }
  
    void solve(vector<vector<int>>& maze, int n, int row, int col, vector<vector<bool>>& visited, 
    string output, vector<string>& ans) {
        if(row == n-1 && col == n-1) {
            ans.push_back(output);
            return;
        }
        
        // for 'D'
        int newRow = row + 1;
        int newCol = col;
        
        if(isSafe(maze, visited, n, newRow, newCol)) {
            visited[newRow][newCol] = true;
            output.push_back('D');
            
            solve(maze, n, newRow, newCol, visited, output, ans);
            
            output.pop_back();
            visited[newRow][newCol] = false;
        }
        
        // for 'L'
        newRow = row;
        newCol = col - 1;
        
        if(isSafe(maze, visited, n, newRow, newCol)) {
            visited[newRow][newCol] = true;
            output.push_back('L');
            
            solve(maze, n, newRow, newCol, visited, output, ans);
            
            output.pop_back();
            visited[newRow][newCol] = false;
        }
        
        //for 'R'
        newRow = row;
        newCol = col + 1;
        
        if(isSafe(maze, visited, n, newRow, newCol)) {
            visited[newRow][newCol] = true;
            output.push_back('R');
            
            solve(maze, n, newRow, newCol, visited, output, ans);
            
            output.pop_back();
            visited[newRow][newCol] = false;
        }
        
        //for 'U'
        newRow = row - 1;
        newCol = col;
        
        if(isSafe(maze, visited, n, newRow, newCol)) {
            visited[newRow][newCol] = true;
            output.push_back('U');
            
            solve(maze, n, newRow, newCol, visited, output, ans);
            
            //backtrack
            output.pop_back();
            visited[newRow][newCol] = false;
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        
        if(maze[0][0] != 1) return ans;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        string output = "";
        
        solve(maze, n, 0, 0, visited, output, ans);
        
        return ans;
    }
};