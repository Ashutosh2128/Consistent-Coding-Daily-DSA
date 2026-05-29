#include<iostream>
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

void flatten(Node* root, Node* &prev) {
    if(!root) return;

    flatten(root -> left, prev);

    prev -> right = root;
    prev -> left = nullptr;
    prev = root;

    flatten(root -> right, prev);
}

void printLL(Node* head) {
    if(!head) return;

    while(head) {
        cout << head -> data << " ";
        head = head -> right;
    }
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

    Node* dummy = new Node(-1);
    Node* prev = dummy;
    flatten(root, prev);
    Node* head = dummy -> right;

    cout << endl << "Printing linked list: ";
    printLL(head);

    return 0;
}