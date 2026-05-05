class Solution {
  public:
    pair<int, int> solve(Node* root) {
        if(!root) return {0, 0};
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        //include current node
        int inc = root -> data + left.second + right.second;
        
        //exclude current node
        int exc = max(left.first, left.second) + max(right.first, right.second);
        
        return {inc, exc};
    }
    
    int getMaxSum(Node *root) {
        pair<int, int> ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};