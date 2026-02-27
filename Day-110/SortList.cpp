class Solution {
public:
    ListNode* findMid(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(!left) return NULL;
        if(!right) return NULL;

        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;

        while(left && right) {
            if(left -> val <= right -> val) {
                it -> next = left;
                it = it -> next;
                left = left -> next;
            }
            else {
                it -> next = right;
                it = it -> next;
                right = right -> next;
            }
        }

        if(left) it -> next = left;
        if(right) it -> next = right;

        return ans -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* mergeLL = merge(left, right);
        return mergeLL;
    }
};