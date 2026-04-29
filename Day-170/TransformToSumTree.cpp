class Solution {
  public:
    int solve(Node* root) {
        if(!root) return 0;
        
        int leftSum = solve(root -> left);
        int rightSum = solve(root -> right);
        
        int value = root -> data;
        
        int sum = leftSum + rightSum;
        root -> data = sum; //change the value at the node
        
        return sum + value;
    }
  
    void toSumTree(Node *node) {
        int ans = solve(node);
    }
};