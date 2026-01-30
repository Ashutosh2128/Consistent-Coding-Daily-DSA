class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<int>& output, vector<vector<int>>& ans, int j) {
        if(target == 0) {
            ans.push_back(output);
            return;
        }
        if(j >= candidates.size() && target > 0) return;

        for(int i = j; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                target -= candidates[i];
                output.push_back(candidates[i]);

                solve(candidates, target, output, ans, i);

                target += candidates[i];
                output.pop_back();
            }
        } 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, output, ans, 0);

        return ans;
    }
};