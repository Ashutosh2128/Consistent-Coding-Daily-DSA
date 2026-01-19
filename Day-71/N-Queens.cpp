class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upparDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;

    bool isSafe(int row, int col) {
        if(rowCheck[row] == true) return false;
        if(upparDiagonalCheck[row-col] == true) return false;
        if(lowerDiagonalCheck[row+col] == true) return false;

        return true;
    }

    void storeAns(vector<vector<char>>& board, vector<vector<string>>& ans, int n) {
        vector<string> tempAns;
        
        for(int i = 0; i < n; i++) {
            string output = "";
            for(int j = 0; j < n; j++) {
                output += board[i][j];
            }

            tempAns.push_back(output);
        }

        ans.push_back(tempAns);
    }

    void solve(vector<vector<char>>& board, vector<vector<string>>& ans, int n, int col) {
        //base case
        if(col >= n) {
            storeAns(board, ans, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upparDiagonalCheck[row-col] = true;
                lowerDiagonalCheck[row+col] = true;

                solve(board, ans, n, col+1);

                board[row][col] = '.';
                rowCheck[row] = false;
                upparDiagonalCheck[row-col] = false;
                lowerDiagonalCheck[row+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        solve(board, ans, n, 0);

        return ans;
    }
};