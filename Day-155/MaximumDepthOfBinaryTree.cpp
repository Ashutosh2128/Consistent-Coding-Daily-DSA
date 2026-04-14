class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftSubTreeHeight = maxDepth(root -> left);
        int rightSubTreeHeight = maxDepth(root -> right);

        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }
};