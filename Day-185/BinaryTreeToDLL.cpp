class Solution {
  public:
    void solve(Node* root, Node* &head, Node* &tail) {
        if(!root) return;
        
        solve(root -> left, head, tail);
        
        if(tail) {
            tail -> right = root;
            root -> left = tail;
            tail = root;
        }
        else {
            head = root;
            tail = root;
        }
        
        solve(root -> right, head, tail);
    }
  
    Node* bToDLL(Node* root) {
        Node* head = nullptr;
        Node* tail = nullptr;
        solve(root, head, tail);
        
        return head;
    }
};






// class Solution {
//   public:
//     void solve(Node* root, Node* &head) {
//         if(!root) return;
        
//         solve(root -> right, head);
        
//         root -> right = head;
//         if(head) head -> left = root;
//         head = root;
        
//         solve(root -> left, head);
//     }
  
//     Node* bToDLL(Node* root) {
//         Node* head = nullptr;
//         solve(root, head);
        
//         return head;
//     }
// };