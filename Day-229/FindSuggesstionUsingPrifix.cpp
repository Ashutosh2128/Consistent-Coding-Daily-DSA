#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TrieNode {
    public:
        char data;
        unordered_map<int, TrieNode*> children;
        bool isTerminal;

        TrieNode(char val) {
            this -> data = val;
            this -> isTerminal = false;
        }
};

void insert(TrieNode* root, string word) {
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

void storeString(TrieNode* root, string& tempAns, vector<string>& ans) {
    //base case
    if(root -> isTerminal) ans.push_back(tempAns);

    for(auto i : root -> children) {
        char ch = i.first;
        TrieNode* child = i.second;
        tempAns.push_back(ch);
        storeString(child, tempAns, ans);
        // back track
        tempAns.pop_back();
    }
}

vector<string> findPrefix(TrieNode* root, string prefix) {
    //base case
    if(prefix.length() == 0) {
        vector<string> ans;
        string tempAns;
        storeString(root, tempAns, ans);

        return ans;
    }

    char ch = prefix[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else {
        child = new TrieNode(ch);
        root -> children[ch] = child;
    }

    return findPrefix(child, prefix.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('_');

    insert(root, "count");
    insert(root, "car");
    insert(root, "cover");
    insert(root, "care");
    insert(root, "cold");
    insert(root, "could");

    string prefix = "co";

    vector<string> ans = findPrefix(root, prefix);

    for(int i = 0; i < ans.size(); i++) {
        cout << prefix + ans[i] << " ";
    } cout << endl;

    return 0;
}