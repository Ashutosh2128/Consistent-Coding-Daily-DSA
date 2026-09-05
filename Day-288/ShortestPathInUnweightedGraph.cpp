class Solution {
  public:
    unordered_map<int, list<int>> addjacency;
  
    void addEdges(int u, int v) {
        addjacency[u].push_back(v);
        addjacency[v].push_back(u);
    }
    
    int shortestPathBFS(int src, int dest) {
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;
        
        queue<int> q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(auto nbr : addjacency[front]) {
                if(!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = front;
                }
            }
        }
        
        // [******** I forget this line during solving *********]
        if(!vis[dest]) return -1; // if dest never visit while traversing from src that means src and dest both are in different component, so finding path is not possible
        
        int pathCount = 0;
        int node = dest;
        while(node != src) {
            pathCount++;
            node = parent[node];
        }
        
        return pathCount;
    }
  
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        for(auto edge : edges) addEdges(edge[0], edge[1]);
        
        return shortestPathBFS(src, dest);
    }
};
