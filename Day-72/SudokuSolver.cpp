class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {
        int n = board.size();

        for(int k = 0; k < n; k++) {
            if(board[k][col] == digit) return false;
        }

        for(int k = 0; k < n; k++) {
            if(board[row][k] == digit) return false;
        }

        for(int k = 0; k < n; k++) {
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit) return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board.size(); col++) {
                if(board[row][col] == '.') {
                    for(char digit = '1'; digit <= '9'; digit++) {
                        if(isSafe(board ,row, col, digit)) {
                            board[row][col] = digit;

                            bool solution = solve(board);

                            if(solution) return true;
                            else board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};