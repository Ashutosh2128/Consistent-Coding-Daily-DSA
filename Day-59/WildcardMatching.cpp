class Solution {
public:
    bool solve(string& s, string& p, int i, int j) {
        if(i == s.length() && j == p.length()) return true;

        if(i == s.length() && j < p.length()) {
            while(j < p.length()) {
                if(p[j] != '*') return false;
                j++;
            }

            return true;
        }

        if(s[i] == p[j] || p[j] == '?') return solve(s, p, i+1, j+1);

        if(p[j] == '*') {
            bool caseA = solve(s, p, i, j+1);

            bool caseB = solve(s, p, i+1, j);

            return caseA || caseB;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};