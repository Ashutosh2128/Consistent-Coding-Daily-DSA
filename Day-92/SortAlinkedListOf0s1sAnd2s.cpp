class Solution {
  public:
    void insertAtTail(Node* &toMove, Node* &head, Node* &tail) {
        if(!head && !tail) {
            head = toMove;
            tail = toMove;
        }
        else {
            tail -> next = toMove;
            tail = toMove;
        }
    }
  
    Node* segregate(Node* head) {
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            Node* toMove = temp;
            temp = temp -> next;
            toMove -> next = NULL;
            
            if(toMove -> data == 0) insertAtTail(toMove, zeroHead, zeroTail);
            else if(toMove -> data == 1) insertAtTail(toMove, oneHead, oneTail);
            else if(toMove -> data == 2) insertAtTail(toMove, twoHead, twoTail);
        }
        
        if(zeroHead) {
            if(oneHead) {
                zeroTail -> next = oneHead;
                oneTail -> next = twoHead;
            }
            else zeroTail -> next = twoHead;
            
            return zeroHead;
        }
        else {
            if(oneHead) {
                oneTail -> next = twoHead;
                return oneHead;
            }
            else return twoHead;
        }
    }
};






// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         int zero = 0;
//         int one = 0;
//         int two = 0;
        
//         Node* temp = head;
        
//         while(temp != NULL) {
//             if(temp -> data == 0) zero++;
//             else if(temp -> data == 1) one++;
//             else if(temp -> data == 2) two++;
            
//             temp = temp -> next;
//         }
        
//         temp = head;
        
//         while(zero--) {
//             temp -> data = 0;
//             temp = temp -> next;
//         }
        
//         while(one--) {
//             temp -> data = 1;
//             temp = temp -> next;
//         }
        
//         while(two--) {
//             temp -> data = 2;
//             temp = temp -> next;
//         }
        
//         return head;
//     }
// };