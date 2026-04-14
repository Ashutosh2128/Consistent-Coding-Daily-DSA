class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root) return 0;

        int leftSubTreeHeight = getHeight(root -> left);
        int rightSubTreeHeight = getHeight(root -> right);

        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int leftDiameter = diameterOfBinaryTree(root -> left);
        int rightDiameter = diameterOfBinaryTree(root -> right);
        int SumOfLeftAndRightHeight = getHeight(root -> left) + getHeight(root -> right);

        return max(leftDiameter, max(rightDiameter, SumOfLeftAndRightHeight));
    }
};