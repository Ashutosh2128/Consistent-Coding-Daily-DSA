class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if(index >= nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> mp;
        for(int i = index; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = true;
                swap(nums[i], nums[index]);

                solve(nums, ans, index+1);

                swap(nums[i], nums[index]);
            }

            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, ans, 0);

        return ans;
    }
};





// class Solution {
// public:
//     map<vector<int>, int> mp;

//     void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
//         if(index >= nums.size() - 1) {
//             if(mp.find(nums) == mp.end()) {
//                 mp[nums]++;
//                 ans.push_back(nums);
//             }
            
//             return;
//         }

//         for(int i = index; i < nums.size(); i++) {
//             swap(nums[i], nums[index]);

//             solve(nums, ans, index+1);

//             swap(nums[i], nums[index]);
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;

//         solve(nums, ans, 0);

//         // set<vector<int>> st;
//         // for(auto i : ans) st.insert(i);
//         // ans.clear();
//         // for(auto i : st) ans.push_back(i);

//         return ans;
//     }
// };