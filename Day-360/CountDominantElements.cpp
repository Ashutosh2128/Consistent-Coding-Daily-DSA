class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;

        int cnt = 0;
        if(nums[0] >= nums[1]) cnt++;
        if(nums[n-1] >= nums[n-2]) cnt++;

        for(int i = 1; i < n-1; i++) if(nums[i] >= ((nums[i-1] + nums[i+1])/2.0)) cnt++;

        return cnt;
    }
};