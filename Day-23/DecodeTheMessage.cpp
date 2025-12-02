class Solution {
public:
    string decodeMessage(string key, string message) {
        int keyLen = key.length();
        unordered_map<int, int> mp;

        char ch = 'a';
        for(int i = 0; i < keyLen; i++) {
            if(key[i] != ' ') {
                if(mp.find(key[i]) == mp.end()) {
                    mp[key[i]] = ch++;
                }
            }
        }

        string ans;
        int mesLen = message.length();

        for(int i = 0; i < mesLen; i++) {
            if(message[i] == ' ') ans.push_back(' ');
            else ans.push_back(mp[message[i]]);
        }

        return ans;
    }
};