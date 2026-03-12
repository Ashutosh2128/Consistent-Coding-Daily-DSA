class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        if(s.size() & 1) return -1;
        stack<char> st;
        
        for(char ch: s) {
            if(ch == '{') st.push(ch);
            else {
                if(!st.empty() && st.top() == '{') st.pop();
                else st.push(ch);
            }
        }
        
        int ans = 0;
        while(!st.empty()) {
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            
            if(a == b) ans += 1;
            else ans += 2;
        }
        
        return ans;
    }
};