class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum < x) return -1;
        if(sum == x) return n;
        int target = sum - x; // so here we have to find maximum element sub array having target

        int maxi = INT_MIN;
        int left = 0;
        int right = 0;
        int cSum = 0;
        while(right < n) {
            cSum += nums[right];

            if(cSum == target) maxi = max(maxi, right - left + 1);
            else if(cSum > target) {
                while(left <= right && cSum > target) cSum -= nums[left++];
                if(cSum == target) maxi = max(maxi, right - left + 1);
            }

            right++;
        }

        if(maxi == INT_MIN) return -1; // not found element whose sum is equal to target
        return n - maxi;
    }
};