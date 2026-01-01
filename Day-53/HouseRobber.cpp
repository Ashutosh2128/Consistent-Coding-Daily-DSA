class Solution {
public:
    int solve(vector<int>& nums, int i) {
        //base case
        if(i >= nums.size()) return 0;

        //include
        int inc = nums[i] + solve(nums, i+2);
        //exclude
        int exc = solve(nums, i+1);

        return max(inc, exc);
    }

    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};






// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int maxAmt = 0;
        
//         int sum = 0;
//         for(int i = 0; i < nums.size(); i+=2) {
//             sum += nums[i];

//             if(sum > maxAmt) maxAmt = sum;
//         }

//         sum = 0;
//         for(int i = 1; i < nums.size(); i+=2) {
//             sum += nums[i];

//             if(sum > maxAmt) maxAmt = sum;
//         }

//         return maxAmt;
//     }
// };