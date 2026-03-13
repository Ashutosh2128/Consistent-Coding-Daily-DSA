class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;

        for(int i = 0; i < str.length(); i++) {
            if(s.empty()) s.push(str[i]);
            else if(s.top() == str[i]) s.pop();
            else s.push(str[i]);
        }
        
        string ans = "";
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};