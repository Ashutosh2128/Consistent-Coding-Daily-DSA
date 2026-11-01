class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minEle = INT_MAX;

        for(int n : nums) {
            sum += n;
            minEle = min(minEle, n);
        }

        return sum - minEle * nums.size();
    }
};