class Solution {
public:
    void parentMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if(!root) return;

        if(root -> left) {
            parentMap[root -> left] = root;
            parentMapping(root -> left, parentMap);
        }
        if(root -> right) {
            parentMap[root -> right] = root;
            parentMapping(root -> right, parentMap);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        parentMap[root] = nullptr;
        visited[target] = true;
        q.push(target);

        parentMapping(root, parentMap);

        int levelCount = 0;
        while(!q.empty()) {
            int size = q.size();
            if(levelCount == k) break;
            levelCount++;

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && visited.find(front -> left) == visited.end()) {
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                if(front -> right && visited.find(front -> right) == visited.end()) {
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                if(parentMap[front] && visited.find(parentMap[front]) == visited.end()) {
                    q.push(parentMap[front]);
                    visited[parentMap[front]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;
    }
};