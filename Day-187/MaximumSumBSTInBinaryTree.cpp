class Solution {
public:
    class Info {
        public:
            int maxVal; // from left subtree
            int minVal; // from right sub tree
            int sum;
            bool isBST;
    };

    Info solve(TreeNode* root, int& maxSum) {
        if(!root) {
            Info temp;

            temp.maxVal = INT_MIN;
            temp.minVal = INT_MAX;
            temp.sum = 0;
            temp.isBST = true;

            return temp;
        }

        Info leftAns = solve(root -> left, maxSum);
        Info rightAns = solve(root -> right, maxSum);

        Info currentAns;
        currentAns.maxVal = max(root -> val, max(leftAns.maxVal, rightAns.maxVal));
        currentAns.minVal = min(root -> val, min(leftAns.minVal, rightAns.minVal));
        currentAns.sum = root -> val + leftAns.sum + rightAns.sum;
        currentAns.isBST = leftAns.isBST && rightAns.isBST && (leftAns.maxVal < root -> val) && (rightAns.minVal > root -> val);

        if(currentAns.isBST) maxSum = max(currentAns.sum, maxSum);

        return currentAns;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        Info ans = solve(root, maxSum);
        return maxSum;
    }
};