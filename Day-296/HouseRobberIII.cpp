class Solution {
public:
    int solveUsingRec(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int robbed = root -> val;
        if(root -> left) robbed += solveUsingRec(root -> left -> left, dp) + solveUsingRec(root -> left -> right, dp);
        if(root -> right) robbed += solveUsingRec(root -> right -> left, dp) + solveUsingRec(root -> right -> right, dp);

        int notRobbed = solveUsingRec(root -> left, dp) + solveUsingRec(root -> right, dp);

        return dp[root] = max(robbed, notRobbed);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solveUsingRec(root, dp);
    }
};