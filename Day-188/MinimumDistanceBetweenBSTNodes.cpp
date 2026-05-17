class Solution {
public:
    void solve(TreeNode* root, TreeNode* &prev, int& minDiff) {
        if(!root) return;

        solve(root -> left, prev, minDiff);

        if(prev) {
            int diff = root -> val - prev -> val;
            minDiff = min(diff, minDiff);
        }
        prev = root;

        solve(root -> right, prev, minDiff);
    }

    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;

        solve(root, prev, minDiff);

        return minDiff;
    }
};