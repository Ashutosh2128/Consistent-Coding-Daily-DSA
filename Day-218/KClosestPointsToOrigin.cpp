class Solution {
public:
    class cmp {
        public:
            bool operator()(vector<int>& a, vector<int>& b) {
                int distA = a[0] * a[0] + a[1] * a[1];
                int distB = b[0] * b[0] + b[1] * b[1];

                return distA > distB;
            } 
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, cmp> minHeap;

        for(vector<int> p : points) minHeap.push(p);

        while(!minHeap.empty() && k--) {
            vector<int> topE = minHeap.top();
            minHeap.pop();
            ans.push_back(topE);
        }

        return ans;
    }
};