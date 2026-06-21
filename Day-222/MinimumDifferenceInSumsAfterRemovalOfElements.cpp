class Solution {
public:
    #define ll long long

    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int n = size / 3;

        vector<ll> prefix(size, -1);
        vector<ll> suffix(size, -1);

        priority_queue<ll> maxHeap;
        ll sum = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == n) prefix[i] = sum;
        }

        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        sum = 0;
        for(int i = size-1; i >= 0; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n) suffix[i] = sum;
        }

        ll minDiff = LONG_LONG_MAX;
        for(int i = n-1; i < n*2; i++) minDiff = min(minDiff, (prefix[i] - suffix[i+1]));

        return minDiff;
    }
};