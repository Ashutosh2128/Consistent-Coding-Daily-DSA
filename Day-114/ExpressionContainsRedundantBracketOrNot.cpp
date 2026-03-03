class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<int> st;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') st.push(s[i]);
            else if(s[i] == ')') {
                if(st.top() == '(') return true;
                else {
                    while(st.top() != '(') st.pop();
                    st.pop();
                }
            }
        }
        
        return false;
    }
};
