class Solution {
public:
    unordered_map<int, bool> vis;
    vector<int> ans;

    void solve(TreeNode* root, int level) {
        if(!root) return;

        if(!vis[level]) {
            vis[level] = true;
            ans.push_back(root -> val);
        } 

        // right
        solve(root -> right, level + 1);

        // left
        solve(root -> left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);

        return ans;
    }
};