class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else {
                    int len = i - st.top();
                    longest = max(longest, len);
                }
            }
        }

        return longest;
    }
};









// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int longest = 0;
//         stack<int> st;

//         for(int i = 0; i < s.length(); i++) {
//             if(s[i] == '(') st.push(i);
//             else if(!st.empty()) {
//                 int len = i - st.top() + 1;
//                 longest = max(longest, len);
//                 st.pop();
//             }
//         }

//         return longest;
//     }
// };







// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int longest = 0;
//         stack<char> st;

//         for(int i = 0; i < s.length(); i++) {
//             if(s[i] == '(') st.push('(');
//             else if(!st.empty()) {
//                 longest += 2;
//                 st.pop();
//             }
//         }

//         return longest;
//     }
// };