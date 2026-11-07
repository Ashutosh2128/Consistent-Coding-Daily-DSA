class Solution {
public:
    long long countValidSubstrings(string s) {
        long long validCnt = 0;

        int left = 0;
        int right = 0;

        while(right < s.length()) {
            if(right >= 2 && right-left >= 2 && s[right-2] == 'a' && s[right-1] == 'b' && s[right] == 'c') left++;
            else {
                validCnt += right - left + 1;
                right++;
            }
        }

        return validCnt;
    }
};