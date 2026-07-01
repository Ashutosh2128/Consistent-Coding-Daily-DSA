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

bool searchWord(TrieNode* root, string word) {
    if(word.length() == 0) return root -> isTerminal;

    char ch = word[0];
    TrieNode* child;

    if(ch == '.') {
        bool ans = false;
        for(auto i : root -> children) {
            child = i.second;
            ans = ans || searchWord(child, word.substr(1));
        }
        return ans;
    } else {
        if(root -> children.count(ch) == 1) child = root -> children[ch];
        else return false;
    }

    return searchWord(child, word.substr(1));
}

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('_');
    }
    
    void addWord(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }
};