class Solution {
  public:
    Node* reverse(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* forward = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
  
    Node* addOne(Node* head) {
        //reverse the list 
        Node* revHead = reverse(head);
        
        //Now addition
        Node* temp = revHead;
        Node* tempPrev = NULL;
        int carry = 1;
        
        while(temp != NULL) {
            int num = carry + temp -> data;
            
            int digit = num % 10;
            carry = num / 10;
            temp -> data = digit;
            
            tempPrev = temp;
            temp = temp -> next;
        }
        
        if(carry) {
            Node* newNode = new Node(carry);
            tempPrev -> next = newNode;
        }
        
        head = reverse(revHead);
        
        return head;
    }
};