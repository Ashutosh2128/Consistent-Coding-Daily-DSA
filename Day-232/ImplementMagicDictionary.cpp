class TrieNode {
    public:
        char data;
        unordered_map<int, TrieNode*> children;
        bool isTerminal;

        TrieNode(char ch) {
            this -> data = ch;
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

bool searchInTrie(TrieNode* root, string word, bool misMatch) {
    if(word.length() == 0 && misMatch) return root -> isTerminal;
    else if(word.length() == 0 && misMatch == false) return false;

    char ch = word[0];

    bool ans = false;
    for(auto i : root -> children) {
        if(ch == i.first) ans = ans || searchInTrie(i.second, word.substr(1), misMatch);
        else if(!misMatch) ans =  ans || searchInTrie(i.second, word.substr(1), true);
    }
    return ans;
}

// little bit wrong
// bool searchInTrie(TrieNode* root, string word, bool& misMatch) {
//     if(word.length() == 0 && misMatch) return root -> isTerminal;
//     else if(word.length() == 0 && misMatch == false) return false;

//     char ch = word[0];

//     if(root -> children.count(ch) == 1) return searchInTrie(root -> children[ch], word.substr(1), misMatch);
//     else {
//         if(!misMatch) {
//             bool ans = false;
//             for(auto i : root -> children) {
//                 misMatch = true;
//                 ans =  ans || searchInTrie(i.second, word.substr(1), misMatch);
//                 // if(ans) break;
//             }
//             return ans;
//         } else return false;
//     }
// }

class MagicDictionary {
public:
    TrieNode* root;

    MagicDictionary() {
        root = new TrieNode('_');
    }
    
    void buildDict(vector<string> dictionary) {
        for(string str : dictionary) insert(root, str);
    }
    
    bool search(string searchWord) {
        bool misMatch = false;
        return searchInTrie(root, searchWord, misMatch);
    }
};