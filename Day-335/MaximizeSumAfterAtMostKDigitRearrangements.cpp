class Solution {
public:
    long long digitRearrangement(int num) {
        vector<int> rearrangeArr;
        while(num) {
            rearrangeArr.push_back(num % 10);
            num /= 10;
        }

        sort(rearrangeArr.begin(), rearrangeArr.end());
        
        long long multiply = 1;
        long long rearrange = 0;

        for(int i = 0; i < rearrangeArr.size(); i++) {
            rearrange += multiply * rearrangeArr[i];
            multiply *= 10;
        }

        return rearrange;
    }
    
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> gain(n, 0);
        for(int i = 0; i < n; i++) {
            int rearrange = digitRearrangement(nums[i]);
            if(rearrange > nums[i]) gain[i] = rearrange - nums[i];
        }

        sort(gain.rbegin(), gain.rend());

        long long maximizeSum = accumulate(nums.begin(), nums.end(), 0LL);
        maximizeSum += accumulate(gain.begin(), gain.begin()+k, 0LL);

        return maximizeSum;
    }
};