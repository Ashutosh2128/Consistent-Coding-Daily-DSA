class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* &node = front.first;
            auto& coordinate = front.second;
            int& row = coordinate.first;
            int& col = coordinate.second;

            mp[col][row].insert(node -> val);

            if(node -> left) q.push({node -> left, {row + 1, col - 1}});
            if(node -> right) q.push({node -> right, {row + 1, col + 1}});
        }

        for(auto it: mp) {
            auto& colMap = it.second;
            vector<int> v;

            for(auto colMapIt: colMap) {
                auto& mSet = colMapIt.second;
                v.insert(v.end(), mSet.begin(), mSet.end());
            }

            ans.push_back(v);
        }

        return ans;
    }
};