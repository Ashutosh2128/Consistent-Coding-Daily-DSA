class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if(i >= nums.size()-1) {
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);

            solve(nums, i+1, ans);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, 0, ans);
        
        return ans;
    }
};