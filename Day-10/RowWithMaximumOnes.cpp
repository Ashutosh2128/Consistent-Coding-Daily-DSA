class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2, 0);

        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0; i < row; i++) {
            int count = 0;

            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 1) count++;
            }

            if(ans[1] < count) {
                ans[0] = i;
                ans[1] = count;
            }
        }

        return ans;
    }
};