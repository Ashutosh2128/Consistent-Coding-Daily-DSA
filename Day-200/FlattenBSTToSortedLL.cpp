#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this -> data = val;
            this -> left = nullptr;
            this -> right = nullptr;
        }
};

Node* insert(Node* root, int val) {
    if(!root) return new Node(val);

    if(val < root -> data) root -> left = insert(root -> left, val);
    else root -> right = insert(root -> right, val);

    return root;
}

void printBST(Node* root) {
    if(!root) return;

    printBST(root -> left);
    cout << root -> data << " ";
    printBST(root -> right);
}

void storeInorder(Node* root, vector<int>& inorder) {
    if(!root) return;

    storeInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    storeInorder(root -> right, inorder);
}

void flatten1(Node* &head, vector<int>& inorder) {
    head = new Node(inorder[0]);
    Node* temp = head;

    for(int i = 1; i < inorder.size(); i++) {
        temp -> right = new Node(inorder[i]);
        temp = temp -> right;
    }
}

void printLL(Node* head) {
    if(!head) return;

    while(head) {
        cout << head -> data << " ";
        head = head -> right;
    }
}

void storeInorderNode(Node* root, vector<Node*>& inorderNode) {
    if(!root) return;

    storeInorderNode(root -> left, inorderNode);
    inorderNode.push_back(root);
    storeInorderNode(root -> right, inorderNode);
}

void flatten2(vector<Node*>& inorderNode) {
    int i = 0;
    while(i < inorderNode.size()-1) {
        Node* curr = inorderNode[i];
        Node* next = inorderNode[i+1];
        curr -> left = nullptr;
        curr -> right = next;
        i++;
    }
    inorderNode[i] -> left = nullptr;
    inorderNode[i] -> right = nullptr;
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 13);

    printBST(root);

    //Method-1: Store inorder in vector then create another BST having right node only from that inorder vector
    vector<int> inorder;
    storeInorder(root, inorder);
    Node* head = nullptr;
    flatten1(head, inorder);
    cout << endl << "Printing Linked list method 1: ";
    printLL(head);

    //Method-2: Store inorder nodes in a vector then traverse in each node connect its right to next node doing null to left
    vector<Node*> inorderNode;
    storeInorderNode(root, inorderNode);
    Node* head2 = inorderNode[0];
    flatten2(inorderNode);
    cout << endl << "Printing Linked list method 2: ";
    printLL(head2);

    return 0;
}