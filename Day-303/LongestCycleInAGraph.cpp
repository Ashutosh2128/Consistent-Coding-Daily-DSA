class Solution {
public:
    int n;
    vector<bool> vis;
    vector<bool> dfsTracker;
    vector<int> dist;

    void dfs(int node, vector<int>& edges, int& maxCycle, int currLen) {
        vis[node] = true;
        dfsTracker[node] = true;
        dist[node] = currLen;

        if(edges[node] != -1 && !vis[edges[node]]) dfs(edges[node], edges, maxCycle, currLen+1);
        else if(edges[node] != -1 && dfsTracker[edges[node]]) {
            int cycleLen = dist[node] - dist[edges[node]] + 1;
            maxCycle = max(maxCycle, cycleLen);

            // maxCycle = dist[node] - dist[edges[node]] + 1; // this will not work in different components
        }

        // backtrack
        dfsTracker[node] = false;
    }

    int longestCycle(vector<int>& edges) {
        n = edges.size();
        vis = vector<bool>(n, 0);
        dfsTracker = vector<bool>(n, 0);
        dist = vector<int>(n);

        int maxCycle = -1;

        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, edges, maxCycle, 0);

        return maxCycle;
    }
};