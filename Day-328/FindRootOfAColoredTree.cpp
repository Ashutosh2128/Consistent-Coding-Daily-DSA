class Solution {
public:
    unordered_map<int, list<int>> adjList;

    char nextColor(char ch) {
        if(ch == 'R') return 'B';
        else if(ch == 'B') return 'W';
        // else if(ch == 'W') return 'R';
        else return 'R';
    }
    
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if(nextColor(colors[u]) == colors[v]) {
                adjList[u].push_back(v);
                indegree[v]++;
                outdegree[u]++;
            }
            else if(nextColor(colors[v]) == colors[u]) {
                adjList[v].push_back(u);
                indegree[u]++;
                outdegree[v]++;
            }
            else return -1;
        }

        int root = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] > 1) return -1;
            if(outdegree[i] > 2) return -1;
            
            if(indegree[i] == 0) {
                if(root != -1) return -1;
                root = i;
            }
        }

        return root;
    }
};