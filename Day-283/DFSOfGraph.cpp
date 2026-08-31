class Solution {
  public:
    void dfsHelper(vector<vector<int>>& adj, int src, unordered_map<int, bool>& vis, vector<int>& ans) {
        ans.push_back(src);
        vis[src] = true;
        
        for(int it : adj[src]) if(!vis[it]) dfsHelper(adj, it, vis, ans);
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int, bool> vis;
        vector<int> ans;
        
        for(int i = 0; i < adj.size(); i++) if(!vis[i]) dfsHelper(adj, i, vis, ans); // extra layer of checking for disconnected graph
        
        // dfsHelper(adj, 0, vis, ans);
        
        return ans;
    }
};