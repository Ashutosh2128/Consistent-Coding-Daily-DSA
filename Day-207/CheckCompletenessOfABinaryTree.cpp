class Solution {
public:
    bool solve(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool isRight = true; // This is for checking if right node is empty, but after nodes are present

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            bool isLeft = true; // This is for checking if left node is empty, but after nodes are present
            if(front -> left) {
                q.push(front -> left);
                if(!isRight) return false;
            }
            else isLeft = false;

            if(front -> right) {
                q.push(front -> right);
                if(!isLeft) return false;
            }
            else isRight = false;
        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        return solve(root);
    }
};