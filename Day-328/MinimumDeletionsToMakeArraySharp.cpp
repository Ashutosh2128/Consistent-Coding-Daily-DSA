class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int minDel = 0;

        int i = 0;
        while(i < nums.size()) {
            int j = i+1;

            while(j < nums.size() && nums[j] == nums[i]) {
                minDel++;
                j++;
            }
            i = j;
        }

        return minDel;
    }
};