class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        string ans = "";

        for(int center = 0; center < s.length(); center++) {
            int i = center;
            int j = center;

            while(i >= 0 && j < s.length()) {
                if(isPalindrome(s, i, j)) {
                    int len = j-i+1;
                    if(maxLen < len) {
                        maxLen = len;
                        ans.clear();
                        for(int k = i; k <= j; k++) {
                            ans.push_back(s[k]);
                        }
                    }
                }
                i--;
                j++;
            }

            i = center;
            j = center + 1;

            while(i >= 0 && j < s.length()) {
                if(isPalindrome(s, i, j)) {
                    int len = j-i+1;
                    if(maxLen < len) {
                        maxLen = len;
                        ans.clear();
                        for(int k = i; k <= j; k++) {
                            ans.push_back(s[k]);
                        }
                    }
                }
                i--;
                j++;
            }
        }

        return ans;
    }
};