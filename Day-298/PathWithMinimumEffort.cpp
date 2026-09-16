class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        // initial states
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int currAbsDiff = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // check wheather the current node is destination
            if(x == row-1 && y == col-1) return dist[x][y];

            //otherwise do left, up, right, down movement
            int dx[] = {0, -1, 0, 1};
            int dy[] = {-1, 0, 1, 0};

            for(int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                // check wheather newX and newY is valid or not
                if(newX >= 0 && newY >= 0 && newX < row && newY < col) {
                    int newAbsDiff = abs(heights[x][y] - heights[newX][newY]);

                    // then find the maximum abs difference and store the minimum
                    newAbsDiff = max(currAbsDiff, newAbsDiff);
                    if(newAbsDiff < dist[newX][newY]) {
                        dist[newX][newY] = newAbsDiff;
                        // if found some new max Difference store in pq
                        pq.push({newAbsDiff, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};