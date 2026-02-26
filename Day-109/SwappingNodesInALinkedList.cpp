class Solution {
public:
    int getLength(ListNode* head) {
        if(!head) return 0;
        return 1 + getLength(head -> next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        //case-1
        if(!head || !head -> next) return head;

        int len = getLength(head);
        int lPos = k;
        int rPos = len - k + 1;
        if(lPos > rPos) swap(lPos, rPos);

        //case-2
        if(lPos == rPos) return head;

        //case-3
        if(len == 2) {
            ListNode* nextNode = head -> next;
            nextNode -> next = head;
            head -> next = NULL;
            head = nextNode;

            return head;
        }

        //case-4
        if(lPos == 1) {
            ListNode* ln = head;
            ListNode* rp = head;
            for(int i = 0; i < len - 2; i++) rp = rp -> next;
            ListNode* rn = rp -> next;

            rn -> next = ln -> next;
            rp -> next = ln;
            ln -> next = NULL;
            head = rn;

            return head;
        }

        //case-5
        int numOfNodeBetTwoNode = rPos - lPos - 1;
        if(numOfNodeBetTwoNode == 0) {
            ListNode* lp = head;
            for(int i = 0; i < lPos-2; i++) lp = lp -> next;
            ListNode* ln = lp -> next;
            ListNode* rp = ln;
            ListNode* rn = rp -> next;
            ListNode* rNxt = rn -> next;

            lp -> next = rn;
            rn -> next = ln;
            ln -> next = rNxt;

            return head;
        }
        else {
            //case-6
            ListNode* lp = head;
            for(int i = 0; i < lPos-2; i++) lp = lp -> next;
            ListNode* ln = lp -> next;

            ListNode* rp = head;
            for(int i = 0; i < rPos-2; i++) rp = rp -> next;
            ListNode* rn = rp -> next;
            ListNode* rNxt = rn -> next;

            lp -> next = rn;
            rn -> next = ln -> next;
            rp -> next = ln;
            ln -> next = rNxt;

            return head;
        }
    }
};