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

    if(root -> children.find(ch) != root -> children.end()) child = root -> children[ch];
    else {
        child = new TrieNode(ch);
        root -> children[ch] = child;
    }

    insert(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string>& ans, string& tempAns) {
    if(root -> isTerminal) ans.push_back(tempAns);

    for(auto i : root -> children) {
        char ch = i.first;
        tempAns.push_back(ch);
        storeString(i.second, ans, tempAns);
        //back-track
        tempAns.pop_back();
    }
}

vector<string> findPrefix(TrieNode* root, string prefix) {
    // base case
    if(prefix.length() == 0) {
        vector<string> ans;
        string tempAns;
        storeString(root, ans, tempAns);

        return ans;
    }

    char ch = prefix[0];
    TrieNode* child;

    if(root -> children.find(ch) != root -> children.end()) child = root -> children[ch];
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

    string prefix = "cou";

    vector<vector<string>> ans;

    string tempPrefix = "";
    for(char ch : prefix) {
        tempPrefix += ch;
        vector<string> tempAns = findPrefix(root, tempPrefix);
        for(int i = 0; i < tempAns.size(); i++) tempAns[i] = tempPrefix + tempAns[i];
        ans.push_back(tempAns);
    }


    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        } cout << endl;
    }

    return 0;
}