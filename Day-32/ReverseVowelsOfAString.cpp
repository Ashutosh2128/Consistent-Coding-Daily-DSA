class Solution {
public:
    bool checkVowels(char ch) {
        if((ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U') || (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')) return true;

        return false;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i <= j) {
            if(!checkVowels(s[i])) i++;
            else if(!checkVowels(s[j])) j--;
            else swap(s[i++], s[j--]);
        }

        return s;
    }
};