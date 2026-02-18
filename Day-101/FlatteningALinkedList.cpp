class Solution {
  public:
    Node* merge(Node* l1, Node* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        Node* ans = 0;
        
        if(l1 -> data < l2 -> data) {
            ans = l1;
            l1 -> bottom = merge(l1 -> bottom, l2);
        }
        else {
            ans = l2;
            l2 -> bottom = merge(l1, l2 -> bottom);
        }
        
        return ans;
    }
  
    Node *flatten(Node *root) {
        if(!root) return NULL;
        return merge(root, flatten(root -> next));
    }
};