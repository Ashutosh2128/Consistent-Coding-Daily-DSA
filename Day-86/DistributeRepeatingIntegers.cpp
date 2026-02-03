class Solution {
public:
    bool solve(vector<int>& counts, vector<int>& quantity, int index) {
        //base case
        if(index == quantity.size()) return true;

        for(int i = 0; i < counts.size(); i++) {
            if(counts[i] >= quantity[index]) {
                counts[i] -= quantity[index];

                bool ans = solve(counts, quantity, index+1);
                if(ans) return true;

                counts[i] += quantity[index];
            }
        }

        // if value of quantity index is greater than all counts value
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto num : nums) mp[num]++;

        vector<int> counts;
        for(auto it : mp) counts.push_back(it.second);

        sort(quantity.rbegin(), quantity.rend()); //without this got TLE. Which found fast if not possible
        return solve(counts, quantity, 0);
    }
};