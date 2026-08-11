class Solution {
public:
    int lengthOfLL(ListNode* &head) {
        ListNode* temp = head;
        int len = 0;

        while(temp) {
            len++;
            temp = temp -> next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = lengthOfLL(head);
        if(length == 1) return nullptr;
        int diff = length - n;

        if(diff == 0) return head -> next;

        ListNode* temp = head;
        for(int i = 0; i < diff - 1; i++) temp = temp -> next;

        ListNode* tempNxt = temp -> next;
        temp -> next = tempNxt -> next ? tempNxt -> next : nullptr;
        if(tempNxt -> next) tempNxt -> next = nullptr;
        delete tempNxt;

        return head;
    }
};