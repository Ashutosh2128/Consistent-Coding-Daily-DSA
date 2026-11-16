class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if(!root) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        int sum = root -> val + max(0, left) + max(0, right);
        maxSum = max(sum, maxSum);

        return root -> val + max(max(0, left), right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = solve(root);
        return max(ans, maxSum);
    }
};