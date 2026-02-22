class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;

        ListNode* slow = head;
        ListNode* fast = head -> next;
        ListNode* newNode = NULL;

        int sum = 0;
        while(fast) {
            if(fast -> val) {
                sum += fast -> val;
            }
            else {
                slow -> val = sum;
                newNode = slow;
                slow = slow -> next;
                sum = 0;
            }

            fast = fast -> next;
        }

        newNode -> next = NULL;
        while(slow) {
            ListNode* nxt = slow -> next;
            delete slow;
            slow = nxt;
        }

        return head;
    }
};