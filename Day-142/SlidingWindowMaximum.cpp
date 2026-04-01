class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans;

        //process first window
        for(int i = 0; i < k; i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
        }

        //process remaining window
        for(int i = k; i < n; i++) {
            //step-1: store ans
            ans.push_back(nums[q.front()]);

            //step-2: removal
            if(i - q.front() == k) q.pop_front();

            //step-3: addition
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
        }

        //process last window
        ans.push_back(nums[q.front()]);

        return ans;
    }
};