class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, int> tMap;
        int i = 0;

        while(i < s.length()) {
            if(mp.find(s[i]) == mp.end() && tMap.find(t[i]) == tMap.end()) {
                mp[s[i]] = t[i];
                tMap[t[i]] = 1;
                i++;
            }
            else if(mp[s[i]] == t[i]) i++;
            else return false;
        }

        return true;
    }
};






// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.length() != t.length()) return false;

//         unordered_map<char, char> mp;
//         int i = 0;

//         while(i < s.length()) {
//             if(mp.find(s[i]) == mp.end()) {
//                 mp[s[i]] = t[i];
//                 i++;
//             }
//             else if(mp[s[i]] == t[i]) i++;
//             else return false;
//         }

//         return true;
//     }
// };