class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(!head || !head -> next || !head -> next -> next) return ans;

        ListNode* prev = head;
        ListNode* curr = head -> next;
        ListNode* nxt = head -> next -> next;

        int firstCP = 0;
        int lastCP = 0;
        int i = 1;
        int maxDis = 0;
        int minDis = INT_MAX;

        while(nxt) {
            bool isCP = ((curr -> val > prev -> val && curr -> val > nxt -> val)
                        || (curr -> val < prev -> val && curr -> val < nxt -> val));

            if(isCP && ! firstCP) {
                firstCP = i;
                lastCP = i;
            }
            else if(isCP) {
                minDis = min(minDis, (i - lastCP));
                lastCP = i;
            }

            ++i;
            prev = prev -> next;
            curr = curr -> next;
            nxt = nxt -> next;
        }

        if(firstCP == lastCP) return ans;

        ans[0] = minDis;
        ans[1] = lastCP - firstCP;
        return ans;
    }
};