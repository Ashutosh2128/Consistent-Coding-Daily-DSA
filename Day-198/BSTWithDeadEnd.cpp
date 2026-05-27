class Solution {
  public:
    bool ans = false;
    unordered_map<int, bool> vis;
    
    void solve(Node* root) {
        if(!root) return;
        
        vis[root -> data] = true;
        if(!root -> left && !root -> right) {
            int afterEle = root -> data + 1;
            int beforeEle = root -> data - 1 == 0 ? 1 : root -> data - 1;
            
            if(vis.find(afterEle) != vis.end() && vis.find(beforeEle) != vis.end()) {
                ans = true;
                return;
            }
        }
        
        solve(root -> left);
        solve(root -> right);
    }
  
    bool isDeadEnd(Node *root) {
        solve(root);
        
        return ans;
    }
};