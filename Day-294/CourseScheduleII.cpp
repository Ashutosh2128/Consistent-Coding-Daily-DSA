class Solution {
public:
    unordered_map<int, list<int>> adjList;

    vector<int> topoBFS(int n) {
        unordered_map<int, int> indegree;
        for(int i = 0; i < n; i++) indegree[i] = 0;

        for(int i = 0; i < n; i++) for(auto nbr : adjList[i]) indegree[nbr]++;

        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);

            for(auto nbr : adjList[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        if(topo.size() == n) {
            reverse(topo.begin(), topo.end());
            return topo;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto it : prerequisites) adjList[it[0]].push_back(it[1]);
        return topoBFS(numCourses);
    }
};