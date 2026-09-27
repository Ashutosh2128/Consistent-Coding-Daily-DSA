class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> freq;
        int equal = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            int first = nums[i];
            int second = nums[i+1];

            if(first == second) equal++;
            else {
                if(first < second) freq[{first, second}]++;
                else freq[{second, first}]++;
            }
        }

        // Now find out maximum frequency
        int maximum = 0;
        for(auto& p : freq) maximum = max(maximum, p.second);

        return equal + maximum;
    }
};