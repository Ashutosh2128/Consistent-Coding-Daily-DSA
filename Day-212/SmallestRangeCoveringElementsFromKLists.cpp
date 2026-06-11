class Solution {
public:
    class Info {
        public:
            int data;
            int rIndex;
            int cIndex;

            Info(int val, int rIndex, int cIndex) {
                this -> data = val;
                this -> rIndex = rIndex;
                this -> cIndex = cIndex;
            }
    };

    class compare {
        public:
            bool operator()(Info* a, Info* b) {
                return a -> data > b -> data;
            }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int rowLen = nums.size();

        for(int i = 0; i < rowLen; i++) {
            Info* temp = new Info(nums[i][0], i, 0);
            pq.push(temp);
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]); // not need but we are doing for setting the value of ans_start, otherwise the value of ans_start by defaultly will INT_MAX
        }

        int ans_start = mini;
        int ans_end = maxi;

        while(!pq.empty()) {
            Info* front = pq.top();
            pq.pop();

            int frontData = front -> data;
            int rIdx = front -> rIndex;
            int cIdx = front -> cIndex;

            mini = frontData;

            if((maxi - mini) < (ans_end - ans_start)) {
                ans_start = mini;
                ans_end = maxi;
            }

            int currCIdx = nums[rIdx].size();
            if(cIdx + 1 < currCIdx) {
                Info* temp = new Info(nums[rIdx][cIdx+1], rIdx, cIdx+1);
                pq.push(temp);
                maxi = max(maxi, nums[rIdx][cIdx+1]);
                // mini = min(mini, nums[rIdx][cIdx+1]); // No need to check here cause we are comapring it with poped value, so if the poped value is lesser than current then mini will not change
            }
            else break;
        }

        ans.push_back(ans_start);
        ans.push_back(ans_end);

        return ans;
    }
};