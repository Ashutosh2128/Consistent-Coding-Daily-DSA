class Trie {
    public:
        char data;
        unordered_map<int, Trie*> children;
        bool isTerminal;

        Trie(char val) {
            this -> data = val;
            this -> isTerminal = false;
        }
};

void insert(Trie* root, string word) {
    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];

    if(root -> children.count(ch) != 1) root -> children[ch] = new Trie(ch);

    insert(root -> children[ch], word.substr(1));
}

bool search(Trie* root, string word, int& i) {
    if(root -> isTerminal) return true;
    if(word.length() == 0) return root -> isTerminal;

    char ch = word[i++];
    if(root -> children.count(ch) == 1) return search(root -> children[ch], word, i);
    else return false;
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        Trie* root = new Trie('_');

        for(auto str : dictionary) insert(root, str);

        int s = 0;
        int e = 0;
        while(e < sentence.size()) {
            if(sentence[e] == ' ' || e == sentence.size() - 1) {
                int len = e == sentence.size()-1 ? e-s+1 : e-s;
                string subStr = sentence.substr(s, len);
                int i = 0;
                bool found = search(root, subStr, i);
                if(found) ans += sentence.substr(s, i);
                else ans += subStr;

                if(sentence[e] == ' ') ans += " ";
                s = e + 1;
            }

            e++;
        }

        return ans;
    }
};