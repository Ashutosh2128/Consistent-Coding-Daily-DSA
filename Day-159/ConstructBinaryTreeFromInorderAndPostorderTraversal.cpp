/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getIndex(vector<int>& inorder, int start, int end, int target) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == target) return i;
        }

        return -1;
    }

    TreeNode* constructTree(vector<int>& postorder, vector<int>& inorder, int& postorderIndex, int inorderStart, int inorderEnd, int size) {
        if(postorderIndex < 0) return nullptr;
        if(inorderStart > inorderEnd) return nullptr;

        int element = postorder[postorderIndex];
        postorderIndex--;

        TreeNode* root = new TreeNode(element);

        int inorderIndex = getIndex(inorder, inorderStart, inorderEnd, element);

        root -> right = constructTree(postorder, inorder, postorderIndex, inorderIndex + 1, inorderEnd, size);
        root -> left = constructTree(postorder, inorder, postorderIndex, inorderStart, inorderIndex - 1, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        TreeNode* root = constructTree(postorder, inorder, index, 0, inorder.size()-1, inorder.size());
        return root;
    }
};