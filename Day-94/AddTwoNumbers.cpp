class Solution {
public:
    ListNode* solve(ListNode* &l1, ListNode* &l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;

        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = l1 ? l1 -> val : 0;
            int val2 = l2 ? l2 -> val : 0;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            it -> next = new ListNode(digit);
            it = it -> next;

            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }

        ListNode* finalAns = ans -> next;
        delete ans;
        return finalAns;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2);
    }
};