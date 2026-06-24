class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++) mp[words[i]]++;

        int wordLength = words[0].length();
        for(int offset = 0; offset < wordLength; offset++) {
            unordered_map<string, int> visited;
            int count = 0;

            for(int i = offset; i + wordLength <= s.length(); i += wordLength) {
                string subStr = s.substr(i, wordLength);

                if(mp.find(subStr) == mp.end()) {
                    visited.clear();
                    count = 0;
                }
                else {
                    visited[subStr]++;
                    count++;
                }

                while(visited[subStr] > mp[subStr]) {
                    string tempStr = s.substr(i - wordLength * (count-1), wordLength);

                    visited[tempStr]--;
                    count--;
                }

                if(count == words.size()) ans.push_back(i - wordLength * (count-1));
            }
        }

        return ans;
    }
};