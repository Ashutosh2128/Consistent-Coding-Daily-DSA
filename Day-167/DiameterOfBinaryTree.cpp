class Solution {
public:
    int maxDiameter = INT_MIN;

    int height(TreeNode* root) {
        if(!root) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        maxDiameter = max(maxDiameter, (lh + rh));

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = height(root);

        if(ans == 0) return 0;
        return maxDiameter;

    }
};







// Required O(n ^ 2)
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if(!root) return 0;

//         int lh = height(root -> left);
//         int rh = height(root -> right);

//         return 1 + max(lh, rh);
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;

//         int leftDiameter = diameterOfBinaryTree(root -> left);
//         int rightDiameter = diameterOfBinaryTree(root -> right);
//         int sumOfLeftAndRightHeight = height(root -> left) + height(root -> right);

//         return max(leftDiameter, max(rightDiameter, sumOfLeftAndRightHeight));
//     }
// };