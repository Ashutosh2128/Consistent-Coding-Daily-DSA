class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s) {
            if(ch == 'a') st.push(ch);
            else if(ch == 'b') {
                if(!st.empty() && st.top() == 'a') st.push(ch);
                else return false;
            }
            else {
                if(!st.empty() && st.top() == 'b') {
                    st.pop();
                    if(!st.empty() && st.top() == 'a') st.pop();
                    else return false;
                }
                else return false;
            }
        }

        return st.empty();
    }
};



//required complexity O(n^2)
// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size() == 0) return true;

//         int fnd = s.find("abc");
//         if(fnd != string::npos) {
//             string left = s.substr(0, fnd);
//             string right = s.substr(fnd + 3, s.size());

//             return isValid(left + right);
//         }

//         return false;
//     }
// };