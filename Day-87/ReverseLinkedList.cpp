class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        if(curr) forward = curr -> next;

        while(curr != NULL) {
            curr -> next = prev;
            prev = curr;
            curr = forward;
            if(forward) forward = forward -> next;
        }

        return prev;
    }
};