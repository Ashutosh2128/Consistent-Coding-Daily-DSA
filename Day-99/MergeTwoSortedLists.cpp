class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;

        ListNode* it1 = list1;
        ListNode* it2 = list2;

        while(it1 && it2) {
            int data1 = it1 -> val;
            int data2 = it2 -> val;

            if(data1 < data2) {
                it -> next = it1;
                it = it -> next;
                it1  = it1 -> next;
                it -> next = NULL;
            }
            else {
                it -> next = it2;
                it = it -> next;
                it2  = it2 -> next;
                it -> next = NULL;
            }
        }

        if(it1) it -> next = it1;
        if(it2) it -> next = it2;

        return ans -> next;
    }
};