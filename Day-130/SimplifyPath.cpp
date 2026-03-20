class Solution {
public:
    void buildAns(stack<string>& st, string& ans) {
        if(st.empty()) return;

        string top = st.top(); st.pop();
        buildAns(st, ans);
        ans += top;
    }

    string simplifyPath(string path) {
        stack<string> st;

        int i = 0;
        while(i < path.size()) {
            int start = i;
            int end = i+1;

            while(end < path.size() && path[end] != '/') end++;
            i = end;

            string minPath = path.substr(start, end-start);

            if(minPath == "/" || minPath == "/.") continue;
            if(minPath != "/..") {
                st.push(minPath);
            }
            else if(!st.empty()) st.pop();
        }

        string ans = st.empty() ? "/" : "";
        buildAns(st, ans);
        return ans;
    }
};