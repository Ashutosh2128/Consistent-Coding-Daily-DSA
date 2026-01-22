class Solution {
public:
    bool solve(vector<vector<int>>& matrix, int target, int r, int c) {
        if(r >= matrix.size() || c < 0) return false;

        if(matrix[r][c] == target) return true;
        else if(target > matrix[r][c]) return solve(matrix, target, r+1, c);
        else return solve(matrix, target, r, c-1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return solve(matrix, target, 0, matrix[0].size()-1);
    }
};