/*Struture of the node of the linked list is as:

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    int solve(Node* &head, int k) {
        int ans = -1;
        
        Node* temp = head;
        int pos = 0;
        while(temp) {
            ++pos;
            if(pos % k == 0) ans = temp -> data;
            temp = temp -> next;
        }
        
        return ans;
    }
  
    int modularNode(Node *head, int k) {
        // code here
        return solve(head, k);
    }
};