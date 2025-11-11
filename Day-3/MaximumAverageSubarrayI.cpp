class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;

        int i = 0;
        int j = 0;

        double sum = 0;

        while(i < k) {
            sum += nums[i];
            i++;
        }

        double avg = sum / k;
        maxAvg = avg > maxAvg ? avg : maxAvg;

        while(i < nums.size()) {
            sum = sum + nums[i++] - nums[j++];
            avg = sum / k;
            maxAvg = avg > maxAvg ? avg : maxAvg;
        }

        return maxAvg;
    }
};