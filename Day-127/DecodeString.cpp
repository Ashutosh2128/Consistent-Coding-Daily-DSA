class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(char ch: s) {
            if(ch == ']') {
                string stringToDecode = "";
                while(!st.empty() && st.top() != "[") {
                    string top = st.top();
                    st.pop();
                    stringToDecode += top;
                }
                
                st.pop(); // popping the [ operator

                string numericValue = "";
                while(!st.empty() && (st.top()[0] >= '0' && st.top()[0] <= '9')) {
                    numericValue += st.top();
                    st.pop();
                }

                reverse(numericValue.begin(), numericValue.end());
                int n = stoi(numericValue);

                string decodedString = "";
                while(n--)
                    decodedString += stringToDecode;

                st.push(decodedString);
            }
            else {
                string temp = "";
                temp += ch;
                st.push(temp);
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};