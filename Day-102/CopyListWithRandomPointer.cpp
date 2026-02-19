class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL; //edge case

        //step-1: create copy list attach to real
        Node* it = head;
        while(it) {
            Node* newNode = new Node(it -> val);
            newNode -> next = it -> next;
            it -> next = newNode;
            it = it -> next -> next;
        }

        //step-2: add random pointer
        it = head;
        while(it) {
            Node* clone = it -> next;
            clone -> random = it -> random ? it -> random -> next : NULL;
            it = it -> next -> next;
        }

        //step-3: detach those two 
        it = head;
        Node* cloneHead = it -> next;
        while(it) {
            Node* cloneNode = it -> next;
            it -> next = cloneNode -> next;
            cloneNode -> next = cloneNode -> next ? cloneNode -> next -> next : NULL;
            it = it -> next;
        }

        return cloneHead;
    }
};






// Same, required TC-O(n) and SC-O(n)
// class Solution {
// public:
//     Node* copyHelper(Node* &head, unordered_map<Node*, Node*>& mp) {
//         if(!head) return NULL;

//         Node* newNode = new Node(head -> val);
//         mp[head] = newNode;
//         newNode -> next = copyHelper(head -> next, mp);

//         if(head -> random) newNode -> random = mp[head -> random];

//         return newNode;
//     }

//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mp;
//         return copyHelper(head, mp);
//     }
// };




// My solution but required TC-O(n) and SC-O(n)
// class Solution {
// public:
//     Node* copyHelper(Node* &head, unordered_map<Node*, Node*>& mp) {
//         Node* copyList = new Node(-1);
//         Node* it = copyList;
//         Node* temp = head;

//         while(temp) {
//             int data = temp -> val;

//             //New node creat and add
//             Node* newNode = new Node(data);
//             it -> next = newNode;

//             //create map entry
//             mp[temp] = newNode;

//             //increment
//             it = it -> next;
//             temp = temp -> next;
//         }

//         Node* finalCopy = copyList -> next;
//         delete copyList;
//         return finalCopy;
//     }

//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mp;
//         Node* copyList = copyHelper(head, mp); //copy done

//         Node* mainIt = head;
//         Node* copyIt = copyList;
//         while(mainIt) {
//             if(mainIt -> random) {
//                 Node* address = mainIt -> random;
//                 Node* copyAddress = mp[address];
//                 copyIt -> random = copyAddress;
//             }

//             mainIt = mainIt -> next;
//             copyIt = copyIt -> next;
//         }

//         return copyList;
//     }
// };