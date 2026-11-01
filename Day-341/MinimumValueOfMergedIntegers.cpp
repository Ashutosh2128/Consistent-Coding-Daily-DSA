class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int minimum = INT_MAX;

        for(int i = 0; i < nums.size(); i += 2) {
            string first = to_string(nums[i]);
            string second = to_string(nums[i+1]);

            string merge = first + second;

            minimum = min(minimum, stoi(merge));
        }

        return minimum;
    }
};