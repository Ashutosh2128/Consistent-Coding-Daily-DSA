#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode {
    public:
        char value;
        unordered_map<int, TrieNode*> children;
        bool isTerminal;

        TrieNode(char data) {
            this -> value = data;
            isTerminal = false;
        }
};

void insert(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else {
        child = new TrieNode(ch);
        root -> children[ch] = child;
    }

    insert(child, word.substr(1));
}

bool search(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) return root -> isTerminal;

    char ch = word[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else return false;

    return search(child, word.substr(1));
}

void deleteTrie(TrieNode* root, string word) {
    if(word.length() == 0) {
        root -> isTerminal = false;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else return;

    deleteTrie(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('_');

    insert(root, "count");
    insert(root, "car");
    insert(root, "cover");
    insert(root, "care");
    insert(root, "cold");
    insert(root, "tag");
    insert(root, "tail");
    insert(root, "tall");
    insert(root, "topic");

    if(search(root, "topic")) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    deleteTrie(root, "topic");

    if(search(root, "topic")) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 0;
}