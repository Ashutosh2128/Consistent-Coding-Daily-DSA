class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            int rem = nums[i] % k;
            bool sameRem = true;

            for(int j = i; j < n; j++) {
                sum += nums[j];

                if(rem != (nums[j] % k)) sameRem = false;

                if(sameRem && (sum % k == rem)) {
                    int len = j - i + 1;
                    maxLength = max(maxLength, len);
                }
            }
        }

        return maxLength;
    }
};