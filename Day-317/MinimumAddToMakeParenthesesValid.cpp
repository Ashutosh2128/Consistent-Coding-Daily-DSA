class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for(char ch : s) {
            if(ch == '(') open++;
            else if(open > 0) open--;
            else ans++; // if open is 0 or less
        }

        return ans + open;
    }
};




// Required O(N) TC and O(N) SC
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;

//         for(char ch : s) {
//             if(ch == '(') st.push('(');
//             else if(!st.empty() && st.top() == '(') st.pop();
//             else st.push(')');
//         }

//         return st.size();
//     }
// };