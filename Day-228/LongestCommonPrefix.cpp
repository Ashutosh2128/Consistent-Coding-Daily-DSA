class TrieNode {
    public:
        char data;
        unordered_map<int, TrieNode*> children;
        bool isTerminal;

        TrieNode(char val) {
            this -> data = val;
            isTerminal = false;
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

void findLCP(TrieNode* root, string& ans) {
    //base case
    if(root -> isTerminal) return;

    TrieNode* child;
    if(root -> children.size() == 1) {
        for(auto e : root -> children) {
            ans.push_back(e.first);
            child = e.second;
        }
    }
    else return;

    findLCP(child, ans);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        TrieNode* root = new TrieNode('_');

        for(auto str : strs) insert(root, str);

        findLCP(root, ans);

        return ans;
    }
};