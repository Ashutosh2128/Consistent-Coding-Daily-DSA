class Solution {
public:
    int findElementIdxInInorder(vector<int>& in, int& start, int& end, int& target) {
        for(int i = start; i <= end; i++) if(in[i] == target) return i;
        return -1;
    }

    TreeNode* constructTree(vector<int>& pre, vector<int>& in, int& preIdx, int inStart, int inEnd, int& size) {
        if(preIdx >= size) return nullptr;
        if(inStart > inEnd) return nullptr;

        int element = pre[preIdx++];
        int idxInInorder = findElementIdxInInorder(in, inStart, inEnd, element);

        TreeNode* root = new TreeNode(element);

        root -> left = constructTree(pre, in, preIdx, inStart, idxInInorder-1, size);
        root -> right = constructTree(pre, in, preIdx, idxInInorder+1, inEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        int size = inorder.size();
        return constructTree(preorder, inorder, preIdx, 0, inorder.size()-1, size);
    }
};