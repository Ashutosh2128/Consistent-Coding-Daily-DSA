class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if(!root) return;

        storeInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        storeInorder(root -> right, inorder);
    }

    void updateTree(TreeNode* root, vector<int>& inorder, int& idx) {
        if(!root) return;

        updateTree(root -> left, inorder, idx);
        root -> val = inorder[idx++];
        updateTree(root -> right, inorder, idx);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        // if(!root -> left && !root -> right) return root;

        vector<int> inorder;
        storeInorder(root, inorder);

        int n = inorder.size();
        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n) inorder[i] = inorder[i] + inorder[i+1];
        }

        int idx = 0;
        updateTree(root, inorder, idx);

        return root;
    }
};