class Solution {
public:
    void nextGreaterElement(vector<int>& arr, vector<int>& ans) {
        int n = arr.size();
        stack<int> st;
        st.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            if(arr[st.top()] > arr[i]) ans[i] = st.top() - i;
            else {
                while(!st.empty()) {
                    if(arr[st.top()] > arr[i]) {
                        ans[i] = st.top() - i;
                        break;
                    }
                    else st.pop();
                }
            }

            st.push(i);
        }
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        nextGreaterElement(temperatures, ans);

        return ans;
    }
};