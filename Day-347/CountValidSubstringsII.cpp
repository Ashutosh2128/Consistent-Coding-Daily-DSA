class Solution {
public:
    long long countValidSubstrings(string s) {
        long long validCnt = 0;

        int lastA = -1;
        int lastAB = -1;
        int invalid = -1;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') lastA = i;
            else if(s[i] == 'b' && lastA != -1) lastAB = lastA;
            else if(s[i] == 'c' && lastAB != -1) invalid = lastAB;

            validCnt += i - invalid;
        }

        return validCnt;
    }
};