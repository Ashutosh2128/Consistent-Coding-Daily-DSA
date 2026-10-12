class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        int i = 0, j = n-1;
        int maxProduct = INT_MIN;
        vector<int> ans = {-1, -1};
        
        while(i < j) {
            int first = v[i].first;
            int second = v[j].first;
            int firstIdx = v[i].second;
            int secondIdx = v[j].second;
            
            if(first + second == target) {
                if(first != second) {
                    if(maxProduct < (first * second)) {
                        maxProduct = first * second;
                        if(first > second) ans = {firstIdx, secondIdx};
                        else ans = {secondIdx, firstIdx};
                    }   
                }

                i++;
                j--;
            }
            else if((first + second) > target) j--;
            else i++;
        }

        return ans;
    }
};