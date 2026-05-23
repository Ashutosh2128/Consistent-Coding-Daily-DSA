class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* succ = nullptr;
        Node* curr = root;
        
        while(curr) {
            if(curr -> data <= k -> data) curr = curr -> right;
            else { // curr -> data > k -> data
                succ = curr;
                curr = curr -> left;
            }
        }
        
        if(succ == nullptr) return -1;
        return succ -> data;
    }
};









// class Solution {
//   public:
//     void findSuccessor(Node* root, Node* &k, Node* &succ) {
//         if(!root) return;
        
//         if(!succ) findSuccessor(root -> left, k, succ);
        
//         if(!succ && root -> data > k -> data) {
//             succ = root;
//             return;
//         }
            
//         if(!succ) findSuccessor(root -> right, k, succ);
//     }
  
//     int inOrderSuccessor(Node *root, Node *k) {
//         Node* succ = nullptr;
        
//         findSuccessor(root, k, succ);
        
//         if(succ == nullptr) return -1;
//         return succ -> data;
//     }
// };








// class Solution {
//   public:
//     void storeInorder(Node* root, vector<int>& inorder) {
//         if(!root) return;
        
//         storeInorder(root -> left, inorder);
//         inorder.push_back(root -> data);
//         storeInorder(root -> right, inorder);
//     }
  
//     int binarySearch(vector<int>& inorder, int& k) {
//         int s = 0;
//         int e = inorder.size() - 1;
        
//         while(s <= e) {
//             int mid = s + (e - s) / 2;
            
//             if(inorder[mid] == k) return mid;
//             else if(inorder[mid] < k) s = mid + 1;
//             else e = mid - 1;
//         }
        
//         return -2;
//     }
  
//     int inOrderSuccessor(Node *root, Node *k) {
//         vector<int> inorder;
//         storeInorder(root, inorder);
        
//         int idx = binarySearch(inorder, k -> data);
        
//         return idx + 1 < inorder.size() ? inorder[idx + 1] : -1;
//     }
// };