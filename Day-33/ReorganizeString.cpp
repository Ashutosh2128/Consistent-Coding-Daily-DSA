class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        char maxFreqChar;
        int maxFreqCount = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxFreqCount) {
                maxFreqCount = freq[i];
                maxFreqChar = i + 'a';
            }
        }

        int index = 0;
        while(index < s.length() && maxFreqCount > 0) {
            s[index] = maxFreqChar;
            index += 2;
            maxFreqCount--;
        }

        if(maxFreqCount != 0) return "";

        freq[maxFreqChar - 'a'] = 0;

        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                index = index >= s.length() ? 1 : index;
                s[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }

        return s;
    }
};