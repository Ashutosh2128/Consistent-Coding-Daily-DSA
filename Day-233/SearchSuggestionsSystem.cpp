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

void storeString(TrieNode* root, string& temp, vector<string>& ans) {
    if(!root) return;
    if(root -> isTerminal) ans.push_back(temp);

    for(auto i : root -> children) {
        char ch = i.first;
        TrieNode* node = i.second;

        temp.push_back(ch);
        storeString(node, temp, ans);
        //backtrack
        temp.pop_back();
    }
}

vector<string> searchPrefix(TrieNode* root, string prefix) {
    if(!root) return {};
    if(prefix.length() == 0) {
        vector<string> ans;
        string tempAns;

        storeString(root, tempAns, ans);

        return ans;
    }

    char ch = prefix[0];
    TrieNode* child = root -> children[ch];

    return searchPrefix(child, prefix.substr(1));
} 

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        TrieNode* root = new TrieNode('_');

        for(string& str : products) insert(root, str);

        string tempPrefix = "";
        for(char& word : searchWord) {
            tempPrefix += word;
            vector<string> tempAns = searchPrefix(root, tempPrefix);
            for(int i = 0; i < tempAns.size(); i++) tempAns[i] = tempPrefix + tempAns[i];
            sort(tempAns.begin(), tempAns.end());
            if(tempAns.size() > 3) tempAns.resize(3);
            ans.push_back(tempAns);
        }

        return ans;
    }
};