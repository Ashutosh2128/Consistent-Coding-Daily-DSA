class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int s = 0;
        int e = n-1;
        int mid = s + (e - s) / 2;

        int steps = 0;

        s = 0;
        e = mid-1;        
        while(s <= e) steps += nums[mid] - nums[s++];

        s = mid+1;
        e = n-1;
        while(s <= e) steps += nums[s++] - nums[mid];

        return steps;
    }
};