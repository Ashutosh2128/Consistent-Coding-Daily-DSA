class Solution {
public:
    bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
        return false;
    }

    int solveUsingTabSO2(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> nextRow(n+1, 0);
        // vector<int> currRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--) {
            for(int  prev = -1; prev <= curr; prev++) {
                int inc = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) 
                    inc = cuboids[curr][2] + nextRow[curr+1];

                int exc = nextRow[prev+1];

                nextRow[prev+1] = max(inc, exc);
            }

            // shifting
            // nextRow = currRow;
        }

        return nextRow[-1+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(vector<int>& cuboid : cuboids) sort(cuboid.begin(), cuboid.end()); // Sort each element
        // sort vector by first elements
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        int curr = 0;
        int prev = -1;
        return solveUsingTabSO2(cuboids);
    }
};








// class Solution {
// public:
//     bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
//         if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
//         return false;
//     }

//     int solveUsingTabSO(vector<vector<int>>& cuboids) {
//         int n = cuboids.size();
//         vector<int> nextRow(n+1, 0);
//         vector<int> currRow(n+1, 0);

//         for(int curr = n-1; curr >= 0; curr--) {
//             for(int  prev = curr-1; prev >= -1; prev--) {
//                 int inc = 0;
//                 if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) 
//                     inc = cuboids[curr][2] + nextRow[curr+1];

//                 int exc = nextRow[prev+1];

//                 currRow[prev+1] = max(inc, exc);
//             }

//             // shifting
//             nextRow = currRow;
//         }

//         return nextRow[-1+1];
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for(vector<int>& cuboid : cuboids) sort(cuboid.begin(), cuboid.end()); // Sort each element
//         // sort vector by first elements
//         sort(cuboids.begin(), cuboids.end());

//         int n = cuboids.size();
//         int curr = 0;
//         int prev = -1;
//         return solveUsingTabSO(cuboids);
//     }
// };







// class Solution {
// public:
//     bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
//         if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
//         return false;
//     }

//     int solveUsingTab(vector<vector<int>>& cuboids) {
//         int n = cuboids.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//         for(int curr = n-1; curr >= 0; curr--) {
//             for(int  prev = curr-1; prev >= -1; prev--) {
//                 int inc = 0;
//                 if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) 
//                     inc = cuboids[curr][2] + dp[curr+1][curr+1];

//                 int exc = dp[curr+1][prev+1];

//                 dp[curr][prev+1] = max(inc, exc);
//             }
//         }

//         return dp[0][-1+1];
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for(vector<int>& cuboid : cuboids) sort(cuboid.begin(), cuboid.end()); // Sort each element
//         // sort vector by first elements
//         sort(cuboids.begin(), cuboids.end());

//         int n = cuboids.size();
//         int curr = 0;
//         int prev = -1;
//         return solveUsingTab(cuboids);
//     }
// };









// class Solution {
// public:
//     bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
//         if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
//         return false;
//     }

//     int solveUsingMem(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp) {
//         // base case
//         if(curr >= cuboids.size()) return 0;

//         if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

//         int inc = 0;
//         if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) 
//             inc = cuboids[curr][2] + solveUsingMem(cuboids, curr+1, curr, dp);

//         int exc = solveUsingMem(cuboids, curr+1, prev, dp);

//         dp[curr][prev+1] = max(inc, exc);
//         return dp[curr][prev+1];
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for(vector<int>& cuboid : cuboids) sort(cuboid.begin(), cuboid.end()); // Sort each element
//         // sort vector by first elements
//         sort(cuboids.begin(), cuboids.end());

//         int n = cuboids.size();
//         int curr = 0;
//         int prev = -1;
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solveUsingMem(cuboids, curr, prev, dp);
//     }
// };









// class Solution {
// public:
//     bool isSafeToPlace(vector<int>& c1, vector<int>& c2) {
//         if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]) return true;
//         return false;
//     }

//     int solveUsingRec(vector<vector<int>>& cuboids, int curr, int prev) {
//         // base case
//         if(curr >= cuboids.size()) return 0;

//         int inc = 0;
//         if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])) 
//             inc = cuboids[curr][2] + solveUsingRec(cuboids, curr+1, curr);

//         int exc = solveUsingRec(cuboids, curr+1, prev);

//         return max(inc, exc);
//     }

//     int maxHeight(vector<vector<int>>& cuboids) {
//         for(vector<int>& cuboid : cuboids) sort(cuboid.begin(), cuboid.end()); // Sort each element
//         // sort vector by first elements
//         sort(cuboids.begin(), cuboids.end());

//         int curr = 0;
//         int prev = -1;
//         return solveUsingRec(cuboids, curr, prev);
//     }
// };