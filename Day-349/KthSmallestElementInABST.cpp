class Solution {
public:
    void solve(TreeNode* root, int& k, int& cnt, int& ans) {
        if(!root) return;

        solve(root -> left, k, cnt, ans);

        cnt++;
        if(cnt == k) {
            ans = root -> val;
            return;
        }

        solve(root -> right, k, cnt, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int cnt = 0;
        solve(root, k, cnt, ans);

        return ans;
    }
};