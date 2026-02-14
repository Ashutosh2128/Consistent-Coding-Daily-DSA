class Solution {
public:
    Node* solve(Node* &head) {
        Node* head2 = head;
        Node* tail = NULL;

        while(head2) {
            if(head2 -> child) {
                Node* childNode = solve(head2 -> child);
                Node* temp = head2 -> next;
                head2 -> next = head2 -> child;
                head2 -> next -> prev = head2;
                if(temp) {
                    temp -> prev = childNode;
                    childNode -> next = temp;
                }
                head2 -> child = NULL;
            }

            tail = head2;
            head2 = head2 -> next;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if(!head) return NULL;

        solve(head);

        return head;
    }
};