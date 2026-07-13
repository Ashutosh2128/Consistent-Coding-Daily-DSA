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

void insert(Trie* root, string& word, int i) {
    if(i == word.length()) {
        root -> isTerminal = true;
        return;
    }
    
    char ch = word[i++];
    
    if(root -> children.count(ch) == 0) root -> children[ch] = new Trie(ch);
    
    insert(root -> children[ch], word, i);
}

void findString(Trie* root, string& tempAns, vector<string>& ans) {
    if(root -> isTerminal) ans.push_back(tempAns);
    
    for(auto it : root -> children) {
        tempAns.push_back(it.first);
        findString(it.second, tempAns, ans);
        tempAns.pop_back();
    }
}

vector<string> searchPrefix(Trie* root, string prefix) {
    if(prefix.size() == 0) {
        vector<string> ans;
        string tempAns = "";
        findString(root, tempAns, ans);
        return ans;
    }
    
    char ch = prefix[0];
    if(root -> children.count(ch) == 1) return searchPrefix(root -> children[ch], prefix.substr(1));
    else return {"0"};
}

class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        vector<vector<string>> ans;
        Trie* root = new Trie('_');
        
        for(int i = 0; i < n; i++) insert(root, contact[i], 0); 
        
        string prefix = "";
        for(int i = 0; i < s.length(); i++) {
            prefix += s[i];
            vector<string> tempAns = searchPrefix(root, prefix);
            
            if(tempAns[0] == "0") ans.push_back(tempAns);
            else {
                for(int i = 0; i < tempAns.size(); i++) tempAns[i] = prefix + tempAns[i];
                sort(tempAns.begin(), tempAns.end());
                ans.push_back(tempAns);
            }
        }
        
        return ans;
    }
};