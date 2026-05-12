class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(p -> val < root -> val && q -> val < root -> val) return lowestCommonAncestor(root -> left, p, q);
        if(p -> val > root -> val && q -> val > root -> val) return lowestCommonAncestor(root -> right, p, q);

        return root;
    }
};




// Required O(N) time
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root) return nullptr;
//         if(root == p) return root;
//         if(root == q) return root;

//         TreeNode* left = lowestCommonAncestor(root -> left, p, q);
//         TreeNode* right = lowestCommonAncestor(root -> right, p, q);

//         if(!left && !right) return nullptr;
//         else if(left && !right) return left;
//         else if(!left && right) return right;
//         else return root;
//     }
// };