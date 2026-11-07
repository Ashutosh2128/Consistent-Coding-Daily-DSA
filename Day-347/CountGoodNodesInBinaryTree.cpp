class Solution {
public:
    int goodCounts = 0;

    void solve(TreeNode* root, int maxTillNow) {
        if(!root) return;

        if(root -> val >= maxTillNow) {
            goodCounts++;
            maxTillNow = root -> val;
        }

        // left
        solve(root -> left, maxTillNow);
        // right
        solve(root -> right, maxTillNow);
    }

    int goodNodes(TreeNode* root) {
        int maxTillNow = INT_MIN;
        solve(root, maxTillNow);

        return goodCounts;
    }
};