#include<iostream>
#include<queue>
#include<deque>
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
    root -> left = createTree();
    root -> right = createTree();

    return root;
}

void RightToLeftLevelOrderTraversal(Node* root) {
    if(!root) return;

    queue<Node*> q;
    deque<Node*> dq;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(!front) {
            cout << endl;

            if(!q.empty()) q.push(NULL);

            while(!dq.empty()) {
                cout << dq.back() -> data << " ";
                dq.pop_back();
            }
        }
        else {
            dq.push_back(front);

            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
    }
}

int main() {
    // 5 6 1 -1 -1 7 2 -1 -1 -1 8 -1 10 15 -1 -1 16 -1 -1
    Node* root = createTree();
    cout << "Root node is " << root -> data << endl;

    cout << "Printing Right to Left in Level Order Traversal: ";
    RightToLeftLevelOrderTraversal(root);
    cout << endl;

    return 0;
}