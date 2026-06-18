class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            int required = target - element;

            if(mp.find(required) != mp.end()) return {i, mp[required]};

            mp[element] = i;
        }

        return {-1, -1};
    }
};