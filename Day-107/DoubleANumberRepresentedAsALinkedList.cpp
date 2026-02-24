class Solution {
public:
    void solve(ListNode* head, int& carry) {
        if(!head) return;

        solve(head -> next, carry);

        int product = head -> val * 2 + carry;
        head -> val = product % 10;
        carry = product / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            newNode -> next = head;
            head = newNode;
        }

        return head;
    }
};