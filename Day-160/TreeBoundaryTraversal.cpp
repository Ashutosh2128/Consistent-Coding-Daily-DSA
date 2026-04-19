class Solution {
  public:
    void leftBoundary(Node* root, vector<int>& ans) {
        if(!root) return;
        if(!root -> left && !root -> right) return;
        
        ans.push_back(root -> data);
        
        if(root -> left) leftBoundary(root -> left, ans);
        else leftBoundary(root -> right, ans);
    }
    
    void leafBoundary(Node* root, vector<int>& ans) {
        if(!root) return;
        
        if(!root -> left && !root -> right) ans.push_back(root -> data);
        
        leafBoundary(root -> left, ans);
        leafBoundary(root -> right, ans);
    }
    
    void rightBoundary(Node* root, vector<int>& ans) {
        if(!root) return;
        if(!root -> left && !root -> right) return;
        
        if(root -> right) rightBoundary(root -> right, ans);
        else rightBoundary(root -> left, ans);
        
        ans.push_back(root -> data);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        //step-1 -> Root Node
        ans.push_back(root -> data);
        
        //Step-2 -> Left Subtree -> Left Boundary
        leftBoundary(root -> left, ans);
        
        //Step-3 -> Left Subtree -> Leaf Node
        leafBoundary(root -> left, ans);
        
        //Step-4 -> Right Subtree -> Leaf Node
        leafBoundary(root -> right, ans);
        
        //Step-5 -> Right Subtree -> Leaf Node in reverse
        rightBoundary(root -> right, ans);
        
        return ans;
    }
};