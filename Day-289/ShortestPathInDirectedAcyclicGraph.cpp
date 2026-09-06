class Solution {
  public:
    unordered_map<int, list<pair<int, int>>> addjacency;
    unordered_map<int, bool> vis;
    stack<int> topoSort;
    
    void addEdges(int u, int v, int w) {
        addjacency[u].push_back({v, w});
    }
    
    void topoSortDFS(int src) {
        vis[src] = true;
        
        for(auto nbr : addjacency[src]) if(!vis[nbr.first]) topoSortDFS(nbr.first);
        
        topoSort.push(src);
    }
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        for(auto edge : edges) addEdges(edge[0], edge[1], edge[2]);
        
        topoSortDFS(0);
        
        vector<int> ans(V, INT_MAX);
        ans[topoSort.top()] = 0;
        
        while(!topoSort.empty()) {
            int top = topoSort.top();
            topoSort.pop();
            for(auto nbr : addjacency[top]) {
                int dist = ans[top] + nbr.second;
                ans[nbr.first] = dist < ans[nbr.first] ? dist : ans[nbr.first];
            }
        }
        
        for(int i = 0; i < V; i++) if(ans[i] == INT_MAX) ans[i] = -1;
        
        return ans;
    }
};
