class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root) return 0;

        int leftSubtreeHeight = getHeight(root -> left);
        int rightSubtreeHeight = getHeight(root -> right);

        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        bool diff = abs(leftHeight - rightHeight) <= 1;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        return diff & left && right;
    }
};