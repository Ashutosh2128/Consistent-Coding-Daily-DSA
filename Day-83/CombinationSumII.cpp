class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& output, vector<vector<int>>& ans, int index) {
        if(target == 0) {
            ans.push_back(output);
            return;
        }

        if(target > 0 && index > candidates.size()) return;

        for(int i = index; i < candidates.size(); i++) {
            if(target >= candidates[i]) {
                if(i > index && candidates[i] == candidates[i-1]) continue;
                target -= candidates[i];
                output.push_back(candidates[i]);

                solve(candidates, target, output, ans, i+1);

                target += candidates[i];
                output.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, output, ans, 0);

        //got tle by this approach
        // set<vector<int>> st;

        // for(auto i : ans) {
        //     st.insert(i);
        // }

        // ans.clear();

        // for(auto i : st) {
        //     ans.push_back(i);
        // }

        return ans;
    }
};