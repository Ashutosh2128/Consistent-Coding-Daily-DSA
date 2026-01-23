class Solution {
public:
    void solve(int n, int k, vector<int> comb, vector<vector<int>>& ans, int i) {
        if(k == 0) {
            ans.push_back(comb);
            return;
        }

        for(int ele = i; ele <= n; ele++) {
            comb.push_back(ele);

            solve(n, k-1, comb, ans, ele+1);

            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;

        solve(n, k, comb, ans, 1);

        return ans;
    }
};