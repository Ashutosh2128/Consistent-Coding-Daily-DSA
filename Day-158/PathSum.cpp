class Solution {
public:
    bool validPath(TreeNode* root, int tSum, int sum) {
        if(!root) return false;

        sum += root -> val;

        if(!root -> left && !root -> right) {
            if(sum == tSum) return true;
            else return false;
        }

        bool left = validPath(root -> left, tSum, sum);
        bool right = validPath(root -> right, tSum, sum);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return validPath(root, targetSum, 0);
    }
};