class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast) {
            fast = fast -> next;

            if(fast ) {
                fast = fast -> next;
                slow = slow -> next;
                if(fast == slow) return true;
            }
        }

        return false;
    }
};





// TC - O(n) and SC - O(n)
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == NULL || head -> next == NULL ) return false;

//         unordered_map<ListNode*, bool> mp;

//         ListNode* temp = head;
//         while(temp != NULL) {
//             if(mp[temp]) return true;
            
//             mp[temp] = true;
//             temp = temp -> next;
//         }

//         return false;
//     }
// };