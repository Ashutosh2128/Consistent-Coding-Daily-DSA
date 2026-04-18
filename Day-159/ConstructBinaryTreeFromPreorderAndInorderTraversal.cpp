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
    int getElement(vector<int>& inorder, int start, int end, int target) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == target) return i;
        }

        return -1;
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, int size) {
        if(preorderIndex >= size) return nullptr;
        if(inorderStart > inorderEnd) return nullptr;

        int element = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(element);

        int elementIndexInsideInorder = getElement(inorder, inorderStart, inorderEnd, element);

        root -> left = constructTree(preorder, inorder, preorderIndex, inorderStart, elementIndexInsideInorder - 1, size);
        root -> right = constructTree(preorder, inorder, preorderIndex, elementIndexInsideInorder + 1, inorderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* root = constructTree(preorder, inorder, index, 0, inorder.size()-1, inorder.size());
        return root;
    }
};