class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for(auto num: nums) {
            mp[num]++;
        }

        for(auto i: mp) {
            if(i.second > n/3) ans.push_back(i.first);
        }

        return ans;
    }
};