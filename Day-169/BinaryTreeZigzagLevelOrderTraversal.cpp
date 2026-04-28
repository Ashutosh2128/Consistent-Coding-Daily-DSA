class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> v;

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                v.push_back(front -> val);

                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }

            if(level % 2 != 0) reverse(v.begin(), v.end());

            ans.push_back(v);
            v.clear();
            level++;
        }

        return ans;
    }
};