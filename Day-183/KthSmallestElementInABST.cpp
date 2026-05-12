class Solution {
public:
    void inorderTraversal(TreeNode* root, int& k, int& cnt, int& ans) {
        if(!root) return;

        inorderTraversal(root -> left, k, cnt, ans);
        
        cnt++;
        if(cnt == k) {
            ans = root -> val;
            return;
        }

        inorderTraversal(root -> right, k, cnt, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int ans = -1;
        int cnt = 0;
        inorderTraversal(root, k, cnt, ans);

        return ans;
    }
};







// class Solution {
// public:
//     void storeInorder(TreeNode* root, vector<int>& inorder) {
//         if(!root) return;

//         storeInorder(root -> left, inorder);
//         inorder.push_back(root -> val);
//         storeInorder(root -> right, inorder);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         if(!root) return -1;

//         vector<int> inorder;
//         storeInorder(root, inorder);

//         return inorder[k-1];
//     }
// };