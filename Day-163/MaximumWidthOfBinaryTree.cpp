class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long int maxWidth = 0;
        if(!root) return maxWidth;

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push(make_pair(root, 1));

        while(!q.empty()) {
            unsigned long long int size = q.size();
            unsigned long long int leftMostNodeIndex = q.front().second;
            unsigned long long int rightMostNodeIndex = q.back().second;
            unsigned long long int width = rightMostNodeIndex - leftMostNodeIndex + 1;
            maxWidth = max(maxWidth, width);

            for(int i = 0; i < size; i++) {
                pair<TreeNode*, unsigned long long int> front = q.front();
                q.pop();

                TreeNode* node = front.first;
                unsigned long long int index = front.second;

                if(node -> left) q.push(make_pair(node -> left, index * 2));
                if(node -> right) q.push(make_pair(node -> right, index * 2 + 1));
            }
        }

        return maxWidth;
    }
};