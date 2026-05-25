class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if(!root) return;

        storeInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        storeInorder(root -> right, inorder);
    }

    TreeNode* buildTree(vector<int>& inorder, int s, int e) {
        if(s > e) return nullptr;

        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(inorder[mid]);
        root -> left = buildTree(inorder, s, mid-1);
        root -> right = buildTree(inorder, mid+1, e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        storeInorder(root, inorder);

        return buildTree(inorder, 0, inorder.size() - 1);
    }
};