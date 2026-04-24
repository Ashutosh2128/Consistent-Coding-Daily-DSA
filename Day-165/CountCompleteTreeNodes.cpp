class Solution {
public:
    int leftHeight(TreeNode* root) {
        int count = 0;
        while(root) {
            count++;
            root = root -> left;
        }

        return count;
    }

    int rightHeight(TreeNode* root) {
        int count = 0;
        while(root) {
            count++;
            root = root -> right;
        }

        return count;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1 << lh) - 1;

        int lans = countNodes(root -> left);
        int rans = countNodes(root -> right);
        return 1 + lans + rans;       
    }
};








// class Solution {
// public:
//     int totalCount(TreeNode* root) {
//         if(!root) return 0;

//         int left = 1 + totalCount(root -> left);
//         int right = totalCount(root -> right);

//         return left + right;
//     }

//     int countNodes(TreeNode* root) {
//         if(!root) return 0;

//         return totalCount(root);
//     }
// };