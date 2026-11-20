class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        int ans = 1;

        for(int num : nums) {
            mp[num + 1] = mp[num] + 1;
            mp[num] = mp[num - 1] + 1;

            ans = max(ans, max(mp[num], mp[num + 1]));
        }

        return ans;
    }
};