class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sumOfSquare = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(n % (i+1) == 0) sumOfSquare += nums[i] * nums[i];
        }

        return sumOfSquare;
    }
};