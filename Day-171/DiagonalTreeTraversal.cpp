class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            while(front) {
                ans.push_back(front -> data);
                if(front -> left) q.push(front -> left);
                front = front -> right;
            }
        }
        
        return ans;
    }
};






// Requored O(n logn) complexity
// class Solution {
//   public:
//     void solve(Node* root, map<int, vector<int>>& mp, int d) {
//         if(!root) return;
        
//         mp[d].push_back(root -> data);
        
//         solve(root -> left, mp, d+1);
//         solve(root -> right, mp, d);
//     }
  
//     vector<int> diagonal(Node *root) {
//         vector<int> ans;
        
//         if(!root) return ans;
        
//         map<int, vector<int>> mp;
//         int d = 0;
        
//         solve(root, mp, d);
        
//         for(pair<int, vector<int>> p: mp) {
//             vector<int> v = p.second;
//             for(int i = 0; i < v.size(); i++) {
//                 ans.push_back(v[i]);
//             }
//         }
        
//         return ans;
//     }
// };