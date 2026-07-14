class Solution {
  public:
    string removeDuplicates(string& s) {
        stack<char> st;
        
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++) {
            if(st.top() != s[i]) st.push(s[i]);
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