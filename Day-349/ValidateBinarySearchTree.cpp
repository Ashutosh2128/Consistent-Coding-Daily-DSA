class Solution {
public:
    bool solve(TreeNode* root, long long lb, long long ub) {
        if(!root) return true;

        bool curr = root -> val > lb && root -> val < ub;

        bool left = solve(root -> left, lb, root -> val);
        bool right = solve(root -> right, root -> val, ub);

        return curr && left && right;
    }

    bool isValidBST(TreeNode* root) {
        // int lowerBound = INT_MIN;
        // int upperBound = INT_MAX;
        long long lowerBound = LONG_MIN;
        long long upperBound = LONG_MAX;

        return solve(root, lowerBound, upperBound);
    }
};