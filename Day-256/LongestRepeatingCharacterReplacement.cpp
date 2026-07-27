class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxReplace = INT_MIN;
        
        int l = 0;
        int r = 0;
        freq[s[r] - 'A']++;
        while(r < s.length()) {
            int maxFreq = 0;
            int totalFreq = 0;
            for(const int& it : freq) {
                maxFreq = max(it, maxFreq);
                totalFreq += it;
            }

            if((totalFreq - maxFreq) <= k) {
                maxReplace = max(totalFreq, maxReplace);
                r++;
                if(r < s.length()) freq[s[r] - 'A']++;
            }
            else {
                freq[s[l] - 'A']--;
                l++;
            }
        }

        return maxReplace;
    }
};