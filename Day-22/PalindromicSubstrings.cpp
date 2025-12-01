class Solution {
public:
    int expandAroundCenter(string& str, int i, int j) {
        int count = 0;
        while(i >= 0 && j < str.length() && str[i] == str[j]) {
            count++;
            i--;
            j++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int totalCount = 0;

        for(int center = 0; center < n; center++) {
            //for odd substring
            int i = center;
            int j = center;

            int oddPalSubCount = expandAroundCenter(s, i, j);

            //for even substring
            i = center;
            j = center + 1;

            int evenPalSubCount = expandAroundCenter(s, i, j);

            totalCount = totalCount + oddPalSubCount + evenPalSubCount;
        }

        return totalCount;
    }
};








// Require O(n^2) complexity
// class Solution {
// public:
//     bool checkPalindrome(string str, int s, int e) {
//         while(s <= e) {
//             if(str[s] == str[e]) {
//                 s++;
//                 e--;
//             }
//             else return false;
//         }

//         return true;
//     }

//     int countSubstrings(string s) {
//         int n = s.length();
//         int count = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 if(checkPalindrome(s, i, j)) count++;
//             }
//         }

//         return count;
//     }
// };