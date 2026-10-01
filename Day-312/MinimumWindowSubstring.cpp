class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if(tLen > sLen) return "";

        unordered_map<char, int> sMp;
        unordered_map<char, int> tMp;

        for(char ch : t) tMp[ch]++;

        int ansIdx = -1;
        int ansLen = INT_MAX;

        int st = 0;
        int end = 0;
        int count = 0;

        while(end < sLen) {
            char ch = s[end];
            sMp[ch]++;

            if(sMp[ch] <= tMp[ch]) count++; // to know we have stored required all char in current window

            if(count == tLen) {
                while(sMp[s[st]] > tMp[s[st]]) sMp[s[st++]]--;

                int windowSize = end - st + 1;
                if(windowSize < ansLen) {
                    ansLen = windowSize;
                    ansIdx = st;
                }
            }

            end++;
        }

        if(ansIdx == -1) return "";
        return s.substr(ansIdx, ansLen);
    }
};