class Solution {
public:
    unordered_map<int, int> rowCheck;
    unordered_map<int, int> upparDiagonalCheck;
    unordered_map<int, int> lowerDiagonalCheck;

    bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
        if(rowCheck[row]) return false;
        if(upparDiagonalCheck[row-col]) return false;
        if(lowerDiagonalCheck[row+col]) return false;

        //otherwise return true
        return true;
    }

    void storeAns(vector<vector<string>>& ans, vector<vector<char>>& board, int n) {
        vector<string> tempAns;

        for(int i = 0; i < n; i++) {
            string output = "";

            for(int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }

            tempAns.push_back(output);
        }

        ans.push_back(tempAns);
    }

    void solve(int n, int col, vector<vector<string>>& ans, vector<vector<char>> board) {
        if(col >= n) {
            storeAns(ans, board, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upparDiagonalCheck[row-col] = true;
                lowerDiagonalCheck[row+col] = true;

                solve(n, col + 1, ans, board);

                board[row][col] = '.';
                rowCheck[row] = false;
                upparDiagonalCheck[row-col] = false;
                lowerDiagonalCheck[row+col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        solve(n, 0, ans, board);

        return ans.size();
    }
};