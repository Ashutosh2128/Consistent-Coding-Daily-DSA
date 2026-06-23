class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;

        for(int i = 0; i < k; i++) maxHeap.push({nums[i], i});

        for(int i = k; i < nums.size(); i++) {
            ans.push_back(maxHeap.top().first);

            maxHeap.push({nums[i], i});

            while(i - maxHeap.top().second >= k) maxHeap.pop();
        }

        ans.push_back(maxHeap.top().first);
        return ans;
    }
};