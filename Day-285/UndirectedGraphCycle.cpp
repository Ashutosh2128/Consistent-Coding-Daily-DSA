class Solution {
  public:
    unordered_map<int, list<int>> adjacencyList;
    unordered_map<int, bool> vis;
    
    void addEdges(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    
    bool DFSCycle(int src, int parent) {
        vis[src] = true;
        
        for(auto it : adjacencyList[src]) {
            if(!vis[it]){
                bool ans = DFSCycle(it, src);
                if(ans) return ans;
            }
            else if(it != parent) return true; // already visited but not parent then cycle present
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        for(vector<int> it : edges) addEdges(it[0], it[1]);
        
        bool ans = false;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                ans = DFSCycle(i, -1);
                if(ans) return ans;   
            }
        }
        
        return ans;
    }
};











// class Solution {
//   public:
//     unordered_map<int, list<int>> adjacencyList;
//     unordered_map<int, bool> vis;
//     unordered_map<int, int> parent;
    
//     void addEdge(int v, int u) {
//         adjacencyList[u].push_back(v);
//         adjacencyList[v].push_back(u);
//     }
    
//     bool bfsCycle(int i) {
//         queue<int> q;
        
//         q.push(i);
//         vis[i] = true;
//         parent[i] = -1;
        
//         while(!q.empty()) {
//             int top = q.front();
//             q.pop();
            
//             for(auto it : adjacencyList[top]) {
//                 if(!vis[it]) {
//                     q.push(it);
//                     vis[it] = true;
//                     parent[it] = top;
//                 }
//                 else if(parent[top] != it) return true; // if it already vidited bu not parent of top then cycle present
//             }
//         }
        
//         return false;
//     } 
    
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         for(vector<int> it : edges) addEdge(it[0], it[1]);
        
//         bool ans = false;
//         for(int i = 0; i < V; i++) {
//             if(!vis[i]) {
//                 ans = bfsCycle(i);
//                 if(ans) return ans;
//             }
//         }
        
//         return ans;
//     }
// };