class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> st;
        st.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            if(temperatures[st.top()] > temperatures[i]) ans[i] = st.top() - i;
            else {
                while(!st.empty()) {
                    if(temperatures[st.top()] > temperatures[i]) {
                        ans[i] = st.top() - i;
                        break;
                    }
                    st.pop();
                }
            }

            st.push(i);
        }

        return ans;
    }
};