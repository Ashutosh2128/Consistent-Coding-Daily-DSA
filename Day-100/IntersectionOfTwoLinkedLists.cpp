class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_map<int, int> mp;
        
        Node* temp = head1;
        while(temp) {
            mp[temp -> data]++;
            temp = temp -> next;
        }
        
        temp = head2;
        while(temp) {
            mp[temp -> data]++;
            temp = temp -> next;
        }
        
        Node* ans = new Node(-1);
        Node* it = ans;
        temp = head1;
        while(temp) {
            if(mp[temp -> data] >= 2) {
                it -> next = temp;
                temp = temp -> next;
                it = it -> next;
                it -> next = NULL;
            }
            else temp = temp -> next;
        }
        
        return ans -> next;
    }
};