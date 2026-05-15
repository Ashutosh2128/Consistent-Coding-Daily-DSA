class Solution {
public:
    int getLength(ListNode* head) {
        int cnt = 0;

        while(head) {
            cnt++;
            head = head -> next;
        }

        return cnt;
    }

    TreeNode* solve(ListNode* &head, int n) {
        if(!head || n <= 0) return nullptr;

        TreeNode* leftNode = solve(head, n/2);

        TreeNode* root = new TreeNode(head -> val);
        root -> left = leftNode;
        head = head -> next;

        TreeNode* rightNode = solve(head, n-n/2-1);
        root -> right = rightNode;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        return solve(head, n);
    }
};