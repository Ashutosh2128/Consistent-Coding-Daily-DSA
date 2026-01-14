class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int m, int n, int& maxi) {
        if(i >= m || j >= n) return 0;

        int right = solve(matrix, i, j+1, m, n, maxi);
        int diagonal = solve(matrix, i+1, j+1, m, n, maxi);
        int down = solve(matrix, i+1, j, m, n, maxi);

        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        int ans = solve(matrix, 0, 0, matrix.size(), matrix[0].size(), maxi);
        if(maxi == INT_MIN) return 0;
        return maxi * maxi;
    }
};