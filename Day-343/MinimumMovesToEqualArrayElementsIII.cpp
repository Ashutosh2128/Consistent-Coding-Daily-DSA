class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        
        int maxEle = INT_MIN;
        for(int it : nums) maxEle = max(maxEle, it);

        for(int i = 0; i < nums.size(); i++) moves += maxEle - nums[i];

        return moves;
    }
};