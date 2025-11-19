class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num : nums) {
            mp[num]++;
        }

        vector<int> ans;

        for(auto m : mp) {
            if(m.second == 1) ans.push_back(m.first);
        }

        return ans;
    }
};