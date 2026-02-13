class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;

        auto it = head;
        while(it) {
            count++;
            it = it -> next;
        }

        int eachPartsSize = count / k;
        int extraParts = count % k;

        vector<ListNode*> ans (k, NULL);
        it = head;

        for(int i = 0; i < k && it; i++) {
            ans[i] = it;

            int partSize = eachPartsSize + (extraParts > 0 ? 1 : 0);
            extraParts--;

            for(int j = 0; j < partSize - 1; j++) it = it -> next;

            auto nextPart = it ? it -> next : NULL;
            it -> next = NULL;
            it = nextPart;
        }

        return ans;
    }
};