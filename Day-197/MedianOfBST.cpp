class Solution {
  public:
    void storeInorder(Node* root, vector<int>& inorder) {
        if(!root) return;
        
        storeInorder(root -> left, inorder);
        inorder.push_back(root -> data);
        storeInorder(root -> right, inorder);
    }
  
    int findMedian(Node* root) {
        // Code here
        vector<int> inorder;
        storeInorder(root, inorder);
        
        int n = inorder.size();
        
        return inorder[(0 + n-1) / 2]; 
    }
};