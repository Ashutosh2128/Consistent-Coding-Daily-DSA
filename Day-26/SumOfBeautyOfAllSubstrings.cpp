class Solution {
public:
    int beautySum(string s) {
        unordered_map<int, int> mp;
        int totalBeauty = 0;

        for(int i = 0; i < s.length(); i++) {
            mp.clear();

            for(int j = i; j < s.length(); j++) {
                mp[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it : mp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                int beauty = maxi - mini;
                totalBeauty += beauty;
            }
        }

        return totalBeauty;
    }
};