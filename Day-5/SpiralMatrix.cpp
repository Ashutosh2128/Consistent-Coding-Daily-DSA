class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int rowStart = 0;
        int rowEnd = rowSize - 1;
        int colStart = 0;
        int colEnd = colSize - 1;

        int totalNum = rowSize * colSize;
        int count = 0;
        vector<int> ans;

        while(count < totalNum) {
            //printing first row
            for(int row = colStart; row <= colEnd && count < totalNum; row++) {
                ans.push_back(matrix[rowStart][row]);
                count++;
            }

            rowStart++;

            //printing last column
            for(int col = rowStart; col <= rowEnd & count < totalNum; col++) {
                ans.push_back(matrix[col][colEnd]);
                count++;
            }

            colEnd--;

            //Printing last row
            for(int row = colEnd; row >= colStart && count < totalNum; row--) {
                ans.push_back(matrix[rowEnd][row]);
                count++;
            }

            rowEnd--;

            //printing fist column
            for(int col = rowEnd; col >= rowStart && count < totalNum; col--) {
                ans.push_back(matrix[col][colStart]);
                count++;
            }

            colStart++;
        }

        return ans;
    }
};