class Solution {
public:
    void sanitizingMap(ListNode* curr, unordered_map<int, ListNode*>& mp, int cSum) {
        int temp = cSum;

        while(1) {
            temp += curr -> val;
            if(temp == cSum) break;
            mp.erase(temp);
            curr = curr -> next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;

        ListNode* it = head;
        int cSum = 0;
        unordered_map<int, ListNode*> mp;

        while(it) {
            cSum += it -> val;

            if(cSum == 0) {
                head = it -> next;
                mp.clear();
            }
            else if(mp.find(cSum) != mp.end()) {
                //entry already present
                sanitizingMap(mp[cSum] -> next, mp, cSum);
                mp[cSum] -> next = it -> next;
            }
            else mp[cSum] = it;

            it = it -> next;
        }

        return head;
    }
};