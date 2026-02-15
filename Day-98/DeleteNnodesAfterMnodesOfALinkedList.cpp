class Solution {
  public:
    Node* solve(Node* &head, int n, int m) {
        Node* it = head;
        
        for(int i = 0; i < m-1; i++) {
            if(!it) return head;
            it = it -> next;
        }
        
        if(!it) return head;
        Node* mthNode = it;
        it = it -> next;
        
        for(int i = 0; i < n; i++) {
            if(!it) break;
            
            Node* temp = it -> next;
            // it -> next = nullptr;
            delete it;
            it = temp;
        }
        
        mthNode -> next = it;
        
        if(!it) return head;
        solve(it, n, m);
        return head;
    }
  
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(!head) return NULL;
        if(m == 0) return NULL;
        if(n == 0) return head;
        return solve(head, n, m);
    }
};