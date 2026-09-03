class Solution {
  public:
    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfsPath;
    unordered_map<int, list<int>> addjacency;
    
    void addEdges(int u, int v) {
        addjacency[u].push_back(v);
    }
    
    bool directedDFSCycle(int src) {
        vis[src] = true;
        dfsPath[src] = true;
        
        bool ans = false;
        for(auto nbr : addjacency[src]) {
            if(!dfsPath[nbr] && !vis[nbr]) { // means not in current path and not visited
                ans = ans || directedDFSCycle(nbr);
                dfsPath[nbr] = false;
                if(ans) return ans;
            }
            else if(dfsPath[nbr]) return true; // means in current path and visited also (else if(dfsPath[nbr] && vis[nbr]))
            // else if(dfsPath[nbr] && !vis[nbr]) // this is wrong, if not visited then how it comes under current path?
        }
        
        return ans;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        for(auto it : edges) addEdges(it[0], it[1]);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bool ans = directedDFSCycle(i);
                dfsPath[i] = false;
                if(ans) return ans;
            }
        }
        
        return false;
    }
};








// This gives TLE as using only one vis map
// class Solution {
//   public:
//     unordered_map<int, bool> vis;
//     unordered_map<int, list<int>> addjacency;
    
//     void addEdges(int u, int v) {
//         addjacency[u].push_back(v);
//     }
    
//     bool directedDFSCycle(int src) {
//         vis[src] = true;
        
//         bool ans = false;
//         for(auto nbr : addjacency[src]) {
//             if(!vis[nbr]) {
//                 ans = ans || directedDFSCycle(nbr);
//                 vis[nbr] = false;
//             }
//             else return true;
//         }
        
//         return ans;
//     }
  
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         for(vector<int> it : edges) addEdges(it[0], it[1]);
        
//         for(int i = 0; i < V; i++) {
//             if(!vis[i]) {
//                 bool ans = directedDFSCycle(i);
//                 vis[i] = false;
//                 if(ans) return true;
//             }
//         }
        
//         return false;
//     }
// };