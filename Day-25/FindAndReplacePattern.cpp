class Solution {
public:
    void replace(string& str) {
        unordered_map<char, char> mp;

        char ch = 'a';
        for(int i = 0; i < str.length(); i++) {
            if(mp.find(str[i]) == mp.end()) {
                mp[str[i]] = ch++;
            }
        }

        for(int i = 0; i < str.length(); i++) {
            str[i] = mp[str[i]];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        replace(pattern);

        vector<string> ans;

        for(int i = 0; i < words.size(); i++) {
            string str = words[i];
            replace(str);

            if(str == pattern) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};