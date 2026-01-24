class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int row, int col, int i) {
        //base cases
        if(i >= word.size()) return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[i]) return false;

        //reached here means board charactor and word charactor matched
        char temp = board[row][col];
        board[row][col] = '@';

        bool ans = solve(board, word, row - 1, col, i + 1) // up
                   || solve(board, word, row, col + 1, i + 1) // right
                   || solve(board, word, row + 1, col, i + 1) // down
                   || solve(board, word, row, col - 1, i + 1); // left
                
        //backtrack
        board[row][col] = temp;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(solve(board, word, row, col, 0)) return true;
            }
        }

        return false;
    }
};