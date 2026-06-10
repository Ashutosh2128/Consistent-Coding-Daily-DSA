class Solution {
class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        }
};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int rowLen = lists.size();
        for(int i = 0; i < rowLen; i++) {
            ListNode* temp = lists[i];
            if(temp) pq.push(temp);
        }

        while(!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();

            if(!head && !tail) {
                head = front;
                tail = front;
            }
            else {
                tail -> next = front;
                tail = tail -> next;
            }

            if(front -> next) pq.push(front -> next);
        }

        return head;
    }
};