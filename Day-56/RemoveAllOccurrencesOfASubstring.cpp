class Solution {
public:
    void solve(string& s, string& part) {
        if(s.find(part) == string::npos) return;

        s.erase(s.find(part), part.length());

        solve(s, part);
    }

    string removeOccurrences(string s, string part) {
        solve(s, part);

        return s;
    }
};





// class Solution {
// public:
//     void solve(string& s, string& part) {
//         if(s.find(part) == string::npos) return;

//         int foundIdx = s.find(part);
//         string left = s.substr(0, foundIdx);
//         string right = s.substr(foundIdx + part.length(), s.length());
//         s = left + right;

//         solve(s, part);
//     }

//     string removeOccurrences(string s, string part) {
//         solve(s, part);

//         return s;
//     }
// };