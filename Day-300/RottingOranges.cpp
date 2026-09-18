class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        
        // mainitaining initial state by pushing all the rotten oranges
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) 
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;

        // if there is no fresh orange not anything have to rotten so return 0
        if(!fresh) return 0;

        int minutes = 0;
        vector<pair<int, int>> direction = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        while(!q.empty()) {
            int size = q.size();
            bool rotten = false;

            for(int i = 0; i < size; i++) {
                pair<int, int> front = q.front();
                q.pop();

                for(pair<int, int> dir : direction) {
                    int newX = front.first + dir.first;
                    int newY = front.second + dir.second;

                    // if it is valid index and it's fresh orange then process
                    if(newX >= 0 && newY >= 0 && newX < row && newY < col && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                        rotten = true;
                    }
                }
            }

            if(rotten) minutes++;
        }

        // return total minutes if every fresh becomes rotten, no fresh left
        if(fresh == 0) return minutes;
        return -1;
    }
};