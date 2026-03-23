class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;

        for(int i = 0; i < num.length(); i++) {
            while(!st.empty() && st.top() > num[i] && k) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(!st.empty() && k) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.length() && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans.length() ? ans : "0";
    }
};