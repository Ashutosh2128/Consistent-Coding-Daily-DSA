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

unordered_map<Trie*, int> freq;

void insert(Trie* root, string word) {
    freq[root]++;
    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }
    
    char ch = word[0];
    if(root -> children.count(ch) == 0) root -> children[ch] = new Trie(ch);
    
    insert(root -> children[ch], word.substr(1));
}

void shortestUniquePrefix(Trie* root, string word, string& tempAns) {
    if(word.length() == 0) return;
    if(freq[root] == 1) return;
    tempAns.push_back(word[0]);
    shortestUniquePrefix(root -> children[word[0]], word.substr(1), tempAns);
}

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        vector<string> ans;
        Trie* root = new Trie('_');
        freq[root]++;
        
        for(string str : arr) insert(root, str);
        
        for(string str : arr) {
            string tempAns;
            shortestUniquePrefix(root, str, tempAns);
            ans.push_back(tempAns);
        }
        
        return ans;
    }
};