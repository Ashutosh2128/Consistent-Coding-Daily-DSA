class Solution {
  public:
    pair<int, int> getHeight(Node* root) {
        if(!root) return {0, 0};
        
        pair<int, int> lh = getHeight(root -> left);
        pair<int, int> rh = getHeight(root -> right);
        
        int sum = root -> data;
        
        if(lh.first == rh.first) sum += lh.second > rh.second ? lh.second : rh.second;
        else if(lh.first > rh.first) sum += lh.second;
        else sum += rh.second;
        
        return {1 + max(lh.first, rh.first), sum};
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int, int> height = getHeight(root);
        return height.second;
    }
};