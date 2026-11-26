class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        if(n == 0) return 0;

        unordered_map<char, int> freq;
        int left = 0;
        int right = 0;
        int maxLen = 1;

        while(right < n) {
            int ch = s[right];
            freq[ch]++;

            if(freq[ch] == 1) maxLen = max(maxLen, right - left + 1);

            while(freq[ch] == 2 && left <= right) freq[s[left++]]--;

            right++;
        }

        return maxLen;
    }
};