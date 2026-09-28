class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        vector<int> ans;
        for(int i = k; i < nums.size(); i++) {
            // store ans
            ans.push_back(nums[dq.front()]);

            // Remove 
            if(!dq.empty() && i - dq.front() >= k) dq.pop_front();

            // Add
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        // store last ans
        ans.push_back(nums[dq.front()]);
        
        return ans;
    }
};