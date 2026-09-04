class Solution {
  public:
    unordered_map<int, list<int>> adjacency;
    unordered_map<int, int> indegree;
    vector<int> ans;
    
    void addEdges(int u, int v) {
        adjacency[u].push_back(v);
    }
    
    void BFSTopoSort(int V) {
        for(int src = 0; src < V; src++) for(auto nbr : adjacency[src]) indegree[nbr]++;
        
        queue<int> q;
        for(int src = 0; src < V; src++) if(indegree[src] == 0) q.push(src);
        
        while(!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            
            for(auto nbr: adjacency[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        for(auto it : edges) addEdges(it[0], it[1]);
        
        BFSTopoSort(V);
        
        return ans;
    }
};











// class Solution {
//   public:
//     unordered_map<int, list<int>> adjacency;
//     unordered_map<int, bool> vis;
//     vector<int> ans;
    
//     void addEdges(int u, int v) {
//         adjacency[u].push_back(v);
//     }
    
//     void DFSTopoSort(int src) {
//         vis[src] = true;
        
//         for(auto nbr : adjacency[src]) if(!vis[nbr]) DFSTopoSort(nbr);
        
//         ans.push_back(src);
//     }
  
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         for(auto it : edges) addEdges(it[0], it[1]);
        
//         for(int i = 0; i < V; i++) if(!vis[i]) DFSTopoSort(i);
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };