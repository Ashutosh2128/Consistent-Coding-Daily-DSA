class Solution {
  public:
    unordered_map<int, bool> vis;
    vector<int> ans;
    
    void inorder(Node* root) {
        if(!root) return;
        
        inorder(root -> left);
        
        if(vis[root -> data]) ans.push_back(root -> data);
        else vis[root -> data] = true;
        
        inorder(root -> right);
    }
  
    vector<int> findCommon(Node* r1, Node* r2) {
        inorder(r1);
        inorder(r2);
        
        return ans;
    }
};













// class Solution {
//   public:
//     void storeInorder(Node* root, vector<int>& inorder) {
//         if(!root) return;
        
//         storeInorder(root -> left, inorder);
        
//         inorder.push_back(root -> data);
        
//         storeInorder(root -> right, inorder);
//     }
  
//     vector<int> findCommon(Node* r1, Node* r2) {
//         vector<int> inorder1, inorder2;
        
//         storeInorder(r1, inorder1);
//         storeInorder(r2, inorder2);
        
//         unordered_map<int, bool> vis;
//         vector<int> ans;
        
//         for(int it : inorder1) vis[it] = true;
        
//         for(int it : inorder2) if(vis[it]) ans.push_back(it);
        
//         return ans;
//     }
// };