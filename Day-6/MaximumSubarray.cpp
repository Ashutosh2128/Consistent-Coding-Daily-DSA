class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if()

        int maxSum = INT_MIN;
        int sum = 0;

        int i = 0;
        while(i < nums.size()) {
            sum += nums[i];

            if(sum > maxSum) maxSum = sum;
            if(sum < 0) sum = 0;

            i++;
        }

        return maxSum;
    }
};