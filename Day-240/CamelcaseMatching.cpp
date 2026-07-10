class Trie {
    public:
        char data;
        unordered_map<int, Trie*> children;
        bool isTerminal;

        Trie(char ch) {
            this -> data = ch;
            this -> isTerminal = false;
        }
};

void insert(Trie* root, string word) {
    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];

    if(root -> children.find(ch) == root -> children.end()) root -> children[ch] = new Trie(ch);

    insert(root -> children[ch], word.substr(1));
}

bool search(Trie* root, string word) {
    if(word.length() == 0 && root -> isTerminal) return true;
    // if(root -> isTerminal) return false;

    char ch = word[0];

    if(root -> children.find(ch) != root -> children.end()) return search(root -> children[ch], word.substr(1));
    else if((ch >= 'a') && (ch <= 'z')) return search(root, word.substr(1));
    else return false;
}

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie* root = new Trie('_');
        insert(root, pattern);

        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < queries.size(); i++) ans[i] = search(root, queries[i]);

        return ans;
    }
};