class Trie {
    public:
        char data;
        unordered_map<int, Trie*> children;
        int stringNum;

        Trie(char ch) {
            this -> data = ch;
            this -> stringNum = -1;
        }
};

void insert(Trie* root, string& word, int& i, int& idx) {
    if(idx == word.length()) {
        root -> stringNum = i;
        return;
    }

    char ch = word[idx++];

    if(root -> children.count(ch) == 0) root -> children[ch] = new Trie(ch);

    insert(root -> children[ch], word, i, idx);
}

bool checkPalindrome(string& str, int s, int e) {
    while(s <= e) if(str[s++] != str[e--]) return false;
    return true;
}

void searchCase2(Trie* root, string& s, vector<int>& palindrome) {
    if(root -> stringNum != -1) {
        if(checkPalindrome(s, 0, s.size()-1)) palindrome.push_back(root -> stringNum);
    } 

    for(auto it : root -> children) {
        s.push_back(it.first);
        searchCase2(it.second, s, palindrome);
        s.pop_back();
    }
}

void search(Trie* root, string& word, vector<int>& palindrome) {
    Trie* curr = root;

    for(int i = 0; i < word.size(); i++) {
        char ch = word[i];

        // case - 1: reach end of the trie but string left
        if(curr -> stringNum != -1) {
            if(checkPalindrome(word, i, word.size() - 1)) palindrome.push_back(curr -> stringNum);
        }

        if(curr -> children.count(ch) == 1) curr = curr -> children[ch];
        else return;
    }

    //case - 2: string reach to an end but still trie have elements
    string s = "";
    searchCase2(curr, s, palindrome);
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Trie* root = new Trie('_');

        for(int i = 0; i < words.size(); i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            int idx = 0;
            insert(root, str, i, idx);
        }

        for(int i = 0; i < words.size(); i++) {
            vector<int> palindrome;
            search(root, words[i], palindrome);

            for(auto it : palindrome) if(it != i) ans.push_back({i, it});
        }

        return ans;
    }
};