class Solution {
  public:
    void storeInorder(Node* root, vector<int>& inorder) {
        if(!root) return;
        
        storeInorder(root -> left, inorder);
        inorder.push_back(root -> data);
        storeInorder(root -> right, inorder);
    }
    
    void mergeTwoSortedArray(vector<int>& arr1, vector<int>& arr2, vector<int>& merge) {
        int i = 0, j = 0;
        
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) merge.push_back(arr1[i++]);
            else merge.push_back(arr2[j++]);
        }
        
        while(i < arr1.size()) merge.push_back(arr1[i++]);
        while(j < arr2.size()) merge.push_back(arr2[j++]);
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> in1, in2;
        
        storeInorder(root1, in1);
        storeInorder(root2, in2);
        
        vector<int> merge;
        mergeTwoSortedArray(in1, in2, merge);
        
        return merge;
    }
};