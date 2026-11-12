class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestLen = 1;

        for(int i = 0; i < nums.size(); i++) {
            int currLongest = 0;
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] > nums[j-1]) currLongest = j-i+1;
                else break;
                longestLen = max(longestLen, currLongest);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            int currLongest = 0;
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] < nums[j-1]) currLongest = j-i+1;
                else break;
                longestLen = max(longestLen, currLongest);
            }
        }

        return longestLen;
    }
};