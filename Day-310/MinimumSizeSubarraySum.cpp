class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int s = 0;
        int e = 0;
        int sum = 0;

        while(e < nums.size()) {
            sum += nums[e];

            while(sum >= target) {
                minLen = min(minLen, e - s + 1);

                sum -= nums[s];
                s++;
            }

            e++;
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};