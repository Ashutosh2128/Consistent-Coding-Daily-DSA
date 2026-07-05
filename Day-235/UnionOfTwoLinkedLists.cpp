class Solution {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        unordered_map<int, int> mp;
        
        Node* UL = nullptr;
        Node* curr = nullptr;
        
        Node* it = head1;
        while(it) {
            int val = it -> data;
            if(mp.find(val) == mp.end()) {
                mp[val]++;
                if(!UL) {
                    UL = it;
                    curr = it;
                }
                else {
                    curr -> next = it;
                    curr = curr -> next;
                }
            }
            it = it -> next;
        }
        
        it = head2;
        while(it) {
            int val = it -> data;
            if(mp.find(val) == mp.end()) {
                mp[val]++;
                if(!UL) {
                    UL = it;
                    curr = it;
                }
                else {
                    curr -> next = it;
                    curr = curr -> next;
                }
            }
            it = it -> next;
        }
        curr -> next = NULL; // I forget this always
        
        return UL;
    }
};