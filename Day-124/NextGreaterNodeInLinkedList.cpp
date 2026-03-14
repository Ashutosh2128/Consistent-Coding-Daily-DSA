class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while(head) {
            arr.push_back(head -> val);
            head = head -> next;
        }

        vector<int> ans(arr.size());
        stack<int> s;

        for(int i = 0; i < arr.size(); i++) {
            while(!s.empty() && arr[i] > arr[s.top()]) {
                int top = s.top();
                s.pop();
                ans[top] = arr[i];
            }
            s.push(i);
        }

        return ans;
    }
};