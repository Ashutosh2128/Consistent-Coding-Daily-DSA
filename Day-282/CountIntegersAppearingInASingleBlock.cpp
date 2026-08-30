class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        vector<int> freq(101, 0);
        freq[nums[0]]++;
        
        for(int i = 1; i < nums.size(); i++) {
            int block = nums[i];
            if(nums[i-1] != nums[i]) freq[block]++;
        }

        for(int i = 1; i < 101; i++) if(freq[i] == 1) count++;

        return count;
    }
};