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

void insertInTrie(TrieNode* root, string word) {
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

    insertInTrie(child, word.substr(1));
}

bool searchInTrie(TrieNode* root, string word) {
    if(word.length() == 0) return root -> isTerminal;

    char ch = word[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else return false;

    return searchInTrie(child, word.substr(1));
}

bool startsWithHelper(TrieNode* root, string word) {
    if(word.length() == 0) return true;

    char ch = word[0];
    TrieNode* child;

    if(root -> children.count(ch) == 1) child = root -> children[ch];
    else return false;

    return startsWithHelper(child, word.substr(1));
}

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('_');
    }
    
    void insert(string word) {
        insertInTrie(root, word);
    }
    
    bool search(string word) {
        return searchInTrie(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root, prefix);
    }
};