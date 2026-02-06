class Solution {
public:
    ListNode* findMiddle(ListNode* &head, ListNode* &midPrev) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast -> next;

            if(fast != NULL) {
                fast = fast -> next;
                midPrev = slow;
                slow = slow -> next;
            }
        }

        return slow;
    }

    ListNode* reverse(ListNode* &prev, ListNode* &curr) {
        while(curr != NULL) {
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        //edge case
        if(head -> next == NULL) return true; //only one node

        //find prev node of mid and mid node
        ListNode* midPrev;
        ListNode* middle = findMiddle(head, midPrev);

        //break in 2 parts i.e: head to mid prev first half and mid to last second half
        midPrev -> next = NULL;

        //reverse second half
        ListNode* prev = NULL;
        ListNode* curr = middle;
        ListNode* revNode = reverse(prev, curr);

        ListNode* temp1 = head;
        ListNode* temp2 = revNode;

        //Now second half has one extra node than first half that's why the loop is until first half not equal to NULL
        while(temp1 != NULL) {
            if(temp1 -> val != temp2 -> val) return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        return true;
    }
};