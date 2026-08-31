class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        unordered_map<int, bool> vis;
        queue<int> q;
        vector<int> ans;
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto it : adj[top]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        
        return ans;
    }
};