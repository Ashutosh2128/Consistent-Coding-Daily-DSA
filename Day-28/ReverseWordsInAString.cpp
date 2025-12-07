class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        // cout << s;

        int start = 0;
        int end = 0;
        int i = 0;

        while(i < s.length()) {
            while(i < s.length() && s[i] == ' ') {
                i++;
            }
            if(i == s.length()) break;
            while(i < s.length() && s[i] != ' ') {
                s[end++] = s[i++];
            }

            reverse(s.begin()+start, s.begin() + end);
            s[end] = ' ';
            end++;
            start = end;
        }

        s.resize(end-1);
        return s;
    }
};