class Solution {
  public:
    unordered_map<int, list<pair<int, int>>> addjacency;
  
    void addEdges(int u, int v, int w) {
        addjacency[u].push_back({v, w});
    }
    
    vector<int> solve(int V, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i < V-1; i++) {
            for(auto a : addjacency) {
                for(auto b : a.second) {
                    int u = a.first;
                    int v = b.first;
                    int w = b.second;
                    
                    if(dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
                }
            }
        }
        
        for(auto a : addjacency) {
            for(auto b : a.second) {
                int u = a.first;
                int v = b.first;
                int w = b.second;
                
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]) return {-1};
            }
        }
        
        for(int i = 0; i < V; i++) if(dist[i] == INT_MAX) dist[i] = 100000000;
        return dist;
    }
  
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        for(auto edge : edges) addEdges(edge[0], edge[1], edge[2]);
        return solve(V, src);
    }
};
