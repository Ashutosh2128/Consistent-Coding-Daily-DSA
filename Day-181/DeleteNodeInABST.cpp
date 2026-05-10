class Solution {
public:
    int findMaximum(TreeNode* root) {
        if(!root) return -1;
        if(!root -> right) return root -> val;
        return findMaximum(root -> right);
    }

    int findMinimum(TreeNode* root) {
        if(!root) return -1;
        if(!root -> left) return root -> val;
        return findMinimum(root -> left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root -> val == key) {
            // matched
            // four cases:

            // Case - 1: It is a leaf node. Having no left and right child
            if(!root -> left && !root -> right) {
                delete root;
                return nullptr;
            }

            // Case - 2: Only having left child. No right child
            if(root -> left && !root -> right) {
                TreeNode* leftSubTree = root -> left;
                root -> left = nullptr;
                delete root;
                return leftSubTree;
            }

            // Case - 3: Only having right child. No left child
            if(!root -> left && root -> right) {
                TreeNode* rightSubTree = root -> right;
                root -> right = nullptr;
                delete root;
                return rightSubTree;
            }

            // Case - 4: Having both left and right child
            if(root -> left && root -> right) {
                // 2 Cases:
                // Case - 1: Replace with just choota element. Means replacee it with inorder predicessor
                // Just chhota element means max element of left subtree
                // int minVal = findMaximum(root -> left);
                // root -> val = minVal;
                // root -> left = deleteNode(root -> left, minVal);
                // return root;

                // Case - 2: Replace with just bada element. Means replace it with inorder successor 
                // Just bada element means min element of right subree
                int maxVal = findMinimum(root -> right);
                root -> val = maxVal;
                root -> right = deleteNode(root -> right, maxVal);
                return root;
            }
        }
        else {
            // not matched
            if(key < root -> val) root -> left = deleteNode(root -> left, key);
            else root -> right = deleteNode(root -> right, key);
        }

        return root;
    }
};s