int findLength(SinglyLinkedListNode* &head) {
    int len = 0;
    SinglyLinkedListNode* temp = head;
    
    while(temp) {
        ++len;
        temp = temp -> next;
    }
    
    return len;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int length = findLength(llist);
    int pos = length - positionFromTail;
    
    SinglyLinkedListNode* temp = llist;
    for(int i = 0; i < pos-1; i++) {
        temp = temp -> next;
    }
    
    return temp -> data;
}





// void solve(SinglyLinkedListNode* head, int& pos, int& ans) {
//     if(head == nullptr) return;
    
//     solve(head -> next, pos, ans);
    
//     if(pos == 0) ans = head -> data;
//     pos--;
// }

// int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
//     int ans = -1;
    
//     solve(llist, positionFromTail, ans);
    
//     return ans;
// }