class Solution {
public:
    void validPath(TreeNode* root, int tSum, int sum, vector<int>& path, vector<vector<int>>& allPath) {
        if(!root) return;

        sum += root -> val;
        path.push_back(root -> val);

        if(!root -> left && !root -> right) {
            if(sum == tSum) {
                allPath.push_back(path);
                path.pop_back();
                return;
            }
        }

        validPath(root -> left, tSum, sum, path, allPath);
        validPath(root -> right, tSum, sum, path, allPath);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPath;
        vector<int> path;

        validPath(root, targetSum, 0, path, allPath);

        return allPath;
    }
};