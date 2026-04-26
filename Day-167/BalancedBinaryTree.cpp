class Solution {
public:
    bool isBalance = true;

    int height(TreeNode* root) {
        if(!root) return 0;

        int lh = height(root -> left);
        int rh = height(root -> right);

        if(isBalance && abs(lh - rh) > 1) isBalance = false;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return isBalance;
    }
};




// Required O(n ^ 2) TC
// class Solution {
// public:
//     int height(TreeNode* root) {
//         if(!root) return 0;

//         int lh = height(root -> left);
//         int rh = height(root -> right);

//         return 1 + max(lh, rh);
//     }

//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;

//         int leftHeight = height(root -> left);
//         int rightHeight = height(root -> right);
//         bool diff = abs(leftHeight - rightHeight) <= 1;

//         bool left = isBalanced(root -> left);
//         bool right = isBalanced(root -> right);

//         return diff && left && right;
//     }
// };