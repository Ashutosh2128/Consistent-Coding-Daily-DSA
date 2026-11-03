class Solution {
public:
    void solve(TreeNode* root) {
        if(!root) return;

        if(root -> left && root -> right) {
            TreeNode* temp = root -> left;
            root -> left = root -> right;
            root -> right = temp;
        }
        else if(root -> left) {
            root -> right = root -> left;
            root -> left = nullptr;
        }
        else if(root -> right) {
            root -> left = root -> right;
            root -> right = nullptr;
        }

        solve(root -> left);
        solve(root -> right);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);

        return root;
    }
};