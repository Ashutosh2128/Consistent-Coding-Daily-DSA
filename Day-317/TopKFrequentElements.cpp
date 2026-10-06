class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int it : nums) freq[it]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(pair<int, int> p : freq) {
            minHeap.push({p.second, p.first});
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};






// this required O(N logN) tc and O(N) sc
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         vector<pair<int, int>> eleCnt;

//         int cnt = 1;
//         for(int i = 0; i < nums.size(); i++) {
//             if(i+1 < nums.size() && nums[i] == nums[i+1]) cnt++;
//             else {
//                 eleCnt.push_back({cnt, nums[i]});
//                 cnt = 1;
//             }
//         }

//         sort(eleCnt.begin(), eleCnt.end());
//         vector<int> ans;

//         for(int i = eleCnt.size() - 1; i >= 0 && k; i--) {
//             ans.push_back(eleCnt[i].second);
//             k--;
//         }

//         return ans;
//     }
// };