class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left && !right) return left;
        else if(!left && right) return right;
        else if(!left && !right) return nullptr;
        else return root;
    }
};