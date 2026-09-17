class Solution {
public:
    unordered_map<int, bool> vis;

    void DFSTraverse(int node, vector<vector<int>>& isConnected) {
        vis[node] = true;

        for(int j = 0; j < isConnected.size(); j++) if(isConnected[node][j] && !vis[j]) DFSTraverse(j, isConnected);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        
        for(int i = 0; i < isConnected.size(); i++) {
            if(!vis[i]) {
                DFSTraverse(i, isConnected);
                province++;
            }
        }

        return province;
    }
};








// class Solution {
// public:
//     unordered_map<int, bool> vis;

//     void BFSTraverse(int node, vector<vector<int>>& isConnected) {
//         queue<int> q;
//         q.push(node);
//         vis[node] = true;

//         while(!q.empty()) {
//             int front = q.front();
//             q.pop();

//             for(int j = 0; j < isConnected.size(); j++) {
//                 if(isConnected[front][j] && !vis[j]) {
//                     vis[j] = true;
//                     q.push(j);
//                 }
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int province = 0;

//         for(int i = 0; i < isConnected.size(); i++) {
//             if(!vis[i]) {
//                 BFSTraverse(i, isConnected);
//                 province++;
//             }
//         }

//         return province;
//     }
// };