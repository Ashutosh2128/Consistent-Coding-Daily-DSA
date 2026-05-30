class Solution {
  public:
    class Node {
        public:
            int data;
            Node* left;
            Node* right;
            
            Node(int val): data(val), left(nullptr), right(nullptr) {};
    };
    
    Node* insert(Node* root, int val, int& succ) {
        if(!root) return new Node(val);
        
        if(val >= root -> data) root -> right = insert(root -> right, val, succ);
        else {
            succ = root -> data;
            root -> left = insert(root -> left, val, succ);
        }
        
        return root;
    }
  
    vector<int> findLeastGreater(vector<int>& arr) {
        vector<int> ans(arr.size());
        Node* root = nullptr;
        
        for(int i = arr.size()-1; i >= 0; i--) {
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }
        
        return ans;
    }
};








// Got TLE
// class Solution {
//   public:
//     vector<int> findLeastGreater(vector<int>& arr) {
//         vector<int> ans(arr.size(), INT_MAX);
        
//         for(int i = 0; i < arr.size()-1; i++) {
//             for(int j = i+1; j < arr.size(); j++) {
//                 if(arr[j] < ans[i] && arr[j] > arr[i]) ans[i] = arr[j];
//             }
//         }
        
//         for(int i = 0; i < arr.size(); i++) if(ans[i] == INT_MAX) ans[i] = -1;
        
//         return ans;
//     }
// };