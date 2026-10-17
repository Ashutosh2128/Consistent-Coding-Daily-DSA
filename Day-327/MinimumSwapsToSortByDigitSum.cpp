class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({digitSum(nums[i]), nums[i]});

        sort(v.begin(), v.end());
        
        unordered_map<int, int> sortedIdx;
        for(int i = 0; i < n; i++) sortedIdx[v[i].second] = i;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[i] = sortedIdx[nums[i]];

        vector<bool> vis(n, false);
        int swpCnt = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] || mp[i] == i) continue;

            int cycle = 0;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = mp[j];
                cycle++;
            }

            if(cycle) swpCnt += cycle - 1;
        }

        return swpCnt;
    }
};