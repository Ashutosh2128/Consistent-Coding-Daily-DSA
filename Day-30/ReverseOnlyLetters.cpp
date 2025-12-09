class Solution {
public:
    bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i <= j) {
            if(!isLetter(s[i])) i++;
            else if(!isLetter(s[j]))j--;
            else swap(s[i++], s[j--]);
        }

        return s;
    }
};