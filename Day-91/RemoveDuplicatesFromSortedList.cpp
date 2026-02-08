class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head ? head -> next : NULL;

        while(curr != NULL) {
            if(prev -> val == curr -> val) {
                prev -> next = curr -> next;
                curr -> next = NULL;
                delete curr;
            }
            else prev = prev -> next;

            curr = prev -> next;
        }

        return head;
    }
};