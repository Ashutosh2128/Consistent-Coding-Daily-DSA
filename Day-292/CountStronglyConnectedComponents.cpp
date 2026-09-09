class Solution {
  public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> vis;
    stack<int> s;
    
    void addEdges(int u, int v) {
        adjList[u].push_back(v);
    }
    
    void topoDFS(int src) {
        vis[src] = true;
        
        for(auto nbr : adjList[src]) if(!vis[nbr]) topoDFS(nbr);
        
        s.push(src);
    }
    
    void dfs(int src, unordered_map<int, list<int>>& newAdj, unordered_map<int, bool>& visited) {
        visited[src] = true;
        
        for(auto nbr : newAdj[src]) if(!visited[nbr]) dfs(nbr, newAdj, visited);
    }
    
    int countSCC(int n) {
        // reverse edges
        unordered_map<int, list<int>> newAdj;
        for(int i = 0; i < n; i++) {
            for(auto nbr : adjList[i]) {
                newAdj[nbr].push_back(i);
            }
        }
        
        unordered_map<int, bool> visited;
        int count = 0;
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            
            if(!visited[top]) {
                dfs(top, newAdj, visited);
                count++;
            }
        }   
        
        return count;
    }
    
    int countSCC(int V, vector<vector<int>> &edges) {
        for(auto edge : edges) addEdges(edge[0], edge[1]);
        
        for(int i = 0; i < V; i++) if(!vis[i]) topoDFS(i);
        
        return countSCC(V);
    }
};