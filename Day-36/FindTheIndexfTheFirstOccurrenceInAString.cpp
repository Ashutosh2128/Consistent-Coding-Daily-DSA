class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n-m; i++) {
            for(int j = 0; j < m; j++) {
                if(haystack[i+j] != needle[j]) break;
                if(j == m-1) return i;
            }
        }

        return -1;
    }
};






//passed 69 test cases
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int i = 0;
//         int j = 0;

//         while(i < needle.length()) {
//             while(j < haystack.length() && i < needle.length()) {
//                 if(needle[i] == haystack[j]) {
//                     i++;
//                     j++;
//                 }
//                 else {
//                     i = 0;
//                     j++;
//                 }
//             }

//             if(j >= haystack.length() && i < needle.length()) return -1;
//         }

//         return j - needle.length();
//     }
// };