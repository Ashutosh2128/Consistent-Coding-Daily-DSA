class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int i: nums) freqMap[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(pair<int, int> it: freqMap) {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()) {
            pair<int, int> topE = minHeap.top();
            minHeap.pop();
            ans.push_back(topE.second);
        }

        return ans;
    }
};