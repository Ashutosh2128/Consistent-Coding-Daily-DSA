class Solution {
public:
    int length(ListNode* &head) {
        int c = 0;
        ListNode* it = head;

        while(it) {
            c++;
            it = it -> next;
        }

        return c;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;

        int len = length(head);
        int actualK = k % len;

        if(actualK == 0 || len == 1) return head;

        int traverse = len - actualK;
        ListNode* it = head;
        for(int i = 0; i < traverse - 1; i++) it = it -> next;

        ListNode* rotateIdx = it -> next;
        ListNode* temp = rotateIdx;
        while(temp -> next) temp = temp -> next; //Now temp is at last

        temp -> next = head;
        it -> next = NULL;
        head = rotateIdx;

        return head;
    }
};