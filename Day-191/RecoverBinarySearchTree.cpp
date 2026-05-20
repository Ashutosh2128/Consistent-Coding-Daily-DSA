class Solution {
public:
    void solve(TreeNode* curr, TreeNode* &prev, TreeNode* &FV, TreeNode* &SV) {
        if(!curr) return;

        solve(curr -> left, prev, FV, SV);

        if(prev && curr -> val < prev -> val) {
            if(!FV) FV = prev;
            SV = curr;
        }

        prev = curr;

        solve(curr -> right, prev, FV, SV);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        TreeNode* FV = nullptr;
        TreeNode* SV = nullptr;

        solve(curr, prev, FV, SV);
        if(FV && SV) swap(FV -> val, SV -> val);
    }
};