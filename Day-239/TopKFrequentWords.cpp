class Solution {
public:
    class comp {
        public:
            bool operator()(pair<int, string> a, pair<int, string> b) {
                if(a.first == b.first) return a.second < b.second; //for lexicographical sorting order
                return a.first > b.first;
            }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> minHeap;
        unordered_map<string, int> mp;

        for(auto str : words) mp[str]++;

        for(auto it : mp) {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        
        vector<string> ans;
        while(!minHeap.empty()) {
            auto topE = minHeap.top();
            minHeap.pop();
            ans.push_back(topE.second);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};