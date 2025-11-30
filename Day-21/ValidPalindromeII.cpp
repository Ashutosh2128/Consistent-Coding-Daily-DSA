class Solution {
public:
    bool checkPalindrome(string str, int s, int e) {
        while(s <= e) {
            if(str[s] == str[e]) {
                s++;
                e--;
            }
            else return false;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i <= j) {
            if(s[i] == s[j]) {
                i++; j--;
            }
            else {
                bool firstAns = checkPalindrome(s, i+1, j); //try to check by removing i element
                bool secondAns = checkPalindrome(s, i, j-1); //try to check by removing j element
                return firstAns || secondAns; //If any of true then palindrome otherwise not
            }
        }

        return true;
    }
};