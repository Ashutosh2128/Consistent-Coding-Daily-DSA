class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start];
        int mid = start + (end - start) / 2;

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;

        int left = solve(nums, start, mid);
        int right = solve(nums, mid + 1, end);

        int leftBorderSum = 0;
        for(int i = mid; i >= start; i--) {
            leftBorderSum += nums[i];
            maxLeftBorderSum = leftBorderSum > maxLeftBorderSum ? leftBorderSum : maxLeftBorderSum;
        }

        int rightBorderSum = 0;
        for(int i = mid + 1; i <= end; i++) {
            rightBorderSum += nums[i];
            maxRightBorderSum = rightBorderSum > maxRightBorderSum ? rightBorderSum : maxRightBorderSum;
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(left, max(right, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};