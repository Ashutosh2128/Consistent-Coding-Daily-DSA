class Solution {
  public:
    unordered_map<int, list<pair<int, int>>> addjacency;
  
    void addEdges(int v, int u, int w) {
        addjacency[u].push_back({v, w});
        addjacency[v].push_back({u, w});
    }
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        for(auto edge : edges) addEdges(edge[0], edge[1], edge[2]);
        
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()) {
            auto begin = *(st.begin());
            st.erase(st.begin());
            
            int node = begin.second;
            int nodeDis = begin.first;
            
            for(auto nbr : addjacency[node]) {
                int dis = nodeDis + nbr.second;
                
                if(dis < dist[nbr.first]) {
                    if(st.find({dist[nbr.first], nbr.first}) != st.end()) st.erase({dist[nbr.first], nbr.first}); // means alredy bigger distance present so erase it
                    
                    dist[nbr.first] = dis;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        
        return dist;
        
    }
};