class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        if(m <= n) {
            for(int i = 0; i < m; i++) {
                if(i == m-1 && n-1 > i+1) for(int j = i+2; j < n; j++) ans[i][j] = '.';
                ans[i][i] = '.';
                if(i+1 < n) ans[i][i+1] = '.';
            }
        }
        else {
            for(int i = 0; i < m; i++) {
                if(i >= n-1) ans[i][n-1] = '.';
                else ans[i][i] = ans[i][i+1] = '.';
            }
        }

        return ans;
    }
};