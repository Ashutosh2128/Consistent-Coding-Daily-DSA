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

Node* createTree() {
    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    // cout << "Adding left node for " << val << endl;
    root -> left = createTree();

    // cout << "Adding right node for " << val << endl;
    root -> right = createTree();

    return root;
}

void preOrderTraversal(Node* root) {
    if(!root) return;

    //NLR
    //N
    cout << root -> data << " ";

    //L
    preOrderTraversal(root -> left);

    //R
    preOrderTraversal(root -> right);
}

void inOrderTraversal(Node* root) {
    if(!root) return;

    //LNR
    //L
    inOrderTraversal(root -> left);

    //N
    cout << root -> data << " ";

    //R
    inOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root) {
    if(!root) return;

    //LRN
    //L
    postOrderTraversal(root -> left);

    //R
    postOrderTraversal(root -> right);

    //N
    cout << root -> data << " ";
}

void levelOrderTraversal(Node* root) {
    if(!root) return;

    queue<Node*> q;
    // q.push(root);

    // while(!q.empty()) {
    //     Node* front = q.front();
    //     q.pop();

    //     cout << front -> data << " ";

    //     if(front -> left) q.push(front -> left);
    //     if(front -> right) q.push(front -> right);
    // }

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

int main() {
    // 5 6 1 -1 -1 7 2 -1 -1 -1 8 -1 10 15 -1 -1 16 -1 -1
    Node* root = createTree();
    cout << "Root Node is " << root -> data << endl;

    cout << "Pre order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}