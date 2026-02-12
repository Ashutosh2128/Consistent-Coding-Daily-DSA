class Solution {
public:
    ListNode* checkCycle(ListNode* &head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast) {
            fast = fast -> next;

            if(fast) {
                fast = fast -> next;
                slow = slow -> next;
                if(fast == slow) return fast;
            }
        }

        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) return NULL;

        ListNode* fast = checkCycle(head);
        if(!fast) return NULL;

        ListNode* slow = head;

        while(fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }

        return fast;
    }
};







// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode*, bool> mp;
//         ListNode* temp = head;

//         while(temp) {
//             if(mp[temp]) return temp;
//             mp[temp] = true;
//             temp = temp -> next;
//         }

//         return NULL;
//     }
// };