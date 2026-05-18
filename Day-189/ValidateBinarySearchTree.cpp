class Solution {
public:
    bool solve(TreeNode* root, long long lb, long long ub) {
        if(!root) return true;

        bool current = lb < root -> val && ub > root -> val;

        bool left = solve(root -> left, lb, root -> val);
        bool right = solve(root -> right, root -> val, ub);

        return current && left && right;
    }

    bool isValidBST(TreeNode* root) {
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;

        return solve(root, lb, ub);
    }
};











// class Solution {
// public:
//     void inorderTraversal(TreeNode* root, vector<int>& inorder) {
//         if(!root) return;

//         inorderTraversal(root -> left, inorder);
//         inorder.push_back(root -> val);
//         inorderTraversal(root -> right, inorder);
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int> inorder;
//         inorderTraversal(root, inorder);

//         for(int i = 0; i < inorder.size() - 1; i++) {
//             if(inorder[i] >= inorder[i+1]) return false;       
//         }

//         return true;
//     }
// };