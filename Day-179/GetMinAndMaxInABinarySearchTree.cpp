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
        root = new Node(val);
        return root;
    }
    else {
        if(val < root -> data) root -> left = buildBST(val, root -> left);
        else root -> right = buildBST(val, root -> right);
    }

    return root;
}

void createTree(Node* &root) {
    int val;
    cout << "Enter value for node: " << endl;
    cin >> val;

    while(val != -1) {
        root = buildBST(val, root);
        // cout << "Enter value for node: " << endl;
        cin >> val;
    }
}

void levelOrderTraversal(Node* &root) {
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

int maximum(Node* root) {
    if(!root) return NULL;
    if(root -> right == NULL) return root -> data;
    return maximum(root -> right);
}

int minimum(Node* root) {
    if(!root) return NULL;
    if(root -> left == NULL) return root -> data;
    return minimum(root -> left);
}

int main() {
    Node* root = NULL;

    // 100 50 200 150 40 75 250 -1
    createTree(root);

    levelOrderTraversal(root);

    cout << "Maximum element from the BST: " << maximum(root) << endl; 
    cout << "Minimum element from the BST: " << minimum(root) << endl;

    return 0;
}