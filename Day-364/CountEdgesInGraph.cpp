class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int edges = 0;
        for(auto& v : adj) edges += v.size();
        
        return edges / 2;
    }
};