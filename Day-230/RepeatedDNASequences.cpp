class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;

        for(int i = 0; i + 9 < s.length(); i++) {
            string subStr = s.substr(i, 10);
            if(mp.find(subStr) != mp.end() && mp[subStr] == 1) ans.push_back(subStr);
            mp[subStr]++;
        }

        return ans;
    }
};