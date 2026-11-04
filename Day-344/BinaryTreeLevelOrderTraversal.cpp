class Solution {
public:
    vector<vector<int>> solve(TreeNode* &root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);
        vector<int> temp;

        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if(!top) {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else {
                temp.push_back(top -> val);

                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
            }
        }

        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        return solve(root);
    }
};