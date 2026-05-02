class Solution {
public:
    void solve(TreeNode* root, long long tSum, int& possibleWays) {
        if(!root) return;

        if(tSum == root -> val) possibleWays++;

        solve(root -> left, tSum - root -> val, possibleWays);
        solve(root -> right, tSum - root -> val, possibleWays);
    }    

    int pathSum(TreeNode* root, long long targetSum) {
        int possibleWays = 0;
        if(!root) return 0;

        solve(root, targetSum, possibleWays);

        int left = pathSum(root -> left, targetSum);
        int right = pathSum(root -> right, targetSum);

        return left + right + possibleWays;
    }
};