#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildBST(int val, Node* root) {
    if(!root) {
        Node* root = new Node(val);
        return root;
    }

    if(val < root -> data) root -> left = buildBST(val, root -> left);
    else root -> right = buildBST(val, root -> right);

    return root;
}

void printBST(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else {
            cout << front -> data << " ";

            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
    }
}

void createTree(Node* &root) {
    int val;
    cin >> val;

    while(val != -1) {
        root = buildBST(val, root);
        cin >> val;
    }
}

bool searchInBST(Node* root, int val) {
    if(!root) return false;
    if(root -> data == val) return true;

    if(val < root -> data) searchInBST(root -> left, val);
    else searchInBST(root -> right, val);
}

int main() {
    Node* root = NULL;
    // 100 50 200 150 40 75 250 -1
    createTree(root);
    cout << "Root Node is: " << root -> data << endl;

    cout << "Printing BST: " << endl;
    printBST(root);
    cout << endl;

    int value;
    cout << "Enter the node value you want to search in BST: ";
    cin >> value;

    bool found = searchInBST(root, value);
    if(found) cout << value << " found in BST" << endl;
    else cout << value << " not found in BST" << endl;

    return 0;
}