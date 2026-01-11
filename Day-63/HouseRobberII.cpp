//there is first and last element were connected. They are neighbor
//so we can rob money from the array like eifther from first element to previous of last element
// or from second element to last
// Otherwise all logic same as House Robber I 

class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        if(s > e) return 0;

        //include
        int inc = nums[s] + solve(nums, s + 2, e);

        //exclude
        int exc = 0 + solve(nums, s + 1, e);

        return max(inc, exc);
    }

    int robHelper(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int opt1 = solve(nums, 0, n-2);
        int opt2 = solve(nums, 1, n-1);

        return max(opt1, opt2);
    }

    int rob(vector<int>& nums) {
        return robHelper(nums);
    }
};