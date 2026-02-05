class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL) {
            fast = fast -> next;

            if(fast != NULL) {
                fast = fast -> next;
                slow = slow -> next;
            }
        }

        return slow;
    }
};