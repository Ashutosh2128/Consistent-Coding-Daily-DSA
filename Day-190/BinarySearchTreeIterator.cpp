class BSTIterator {
public:
    stack<TreeNode*> s;
    void pushLeft(TreeNode* root) {
        if(!root) return;
        s.push(root);
        pushLeft(root -> left);
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        
        if(top -> right) pushLeft(top -> right);

        return top -> val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};







// class BSTIterator {
// public:
//     vector<int> inorder;
//     int i = 0;
//     void storeInorder(TreeNode* root) {
//         if(!root) return;

//         storeInorder(root -> left);
//         inorder.push_back(root -> val);
//         storeInorder(root -> right);
//     }

//     BSTIterator(TreeNode* root) {
//         storeInorder(root);
//     }
    
//     int next() {
//         return inorder[i++];
//     }
    
//     bool hasNext() {
//         return i < inorder.size();
//     }
// };