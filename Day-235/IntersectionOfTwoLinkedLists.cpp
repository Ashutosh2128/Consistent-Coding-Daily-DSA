class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        if(a == b) return a;

        while(a -> next && b -> next) {
            if(a == b) return a;
            a = a -> next;
            b = b -> next;
        }

        if(a -> next == nullptr) {
            // b is bigger
            int bLen = 0;
            while(b -> next) {
                bLen++;
                b = b -> next;
            }

            while(bLen--) headB = headB -> next;
        }
        else {
            // a is bigger
            int aLen = 0;
            while(a -> next) {
                aLen++;
                a = a -> next;
            }

            while(aLen--) headA = headA -> next;
        }

        while(headA && headB) {
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }

        return nullptr;
    }
};






// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_map<ListNode*, bool> freq;

//         ListNode* curr = headA;
//         while(curr) {
//             freq[curr] = true;
//             curr = curr -> next;
//         }

//         curr = headB;
//         while(curr) {
//             if(freq[curr]) return curr;
//             freq[curr] = true;
//             curr = curr -> next;
//         }

//         return nullptr;
//     }
// };