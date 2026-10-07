class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> mp;

    vector<int> checkExtras(string& str) {
        stack<char> s;
        for(char ch : str) {
            if(ch >= 'a' && ch <= 'z') continue;
            else if(ch == '(') s.push(ch);
            else if(!s.empty() && s.top() == '(') s.pop();
            else s.push(ch);
        }

        vector<int> extra(2, 0);
        while(!s.empty()) {
            if(s.top() == '(') extra[0]++;
            else extra[1]++;
            s.pop();
        }

        return extra;
    }

    void solve(string& s, string output, int balance, int removeOpen, int removeClose, int i) {
        if(i >= s.length()) {
            if(balance == 0 && removeOpen == 0 && removeClose == 0 && output.length() && mp.find(output) == mp.end()) {
                mp[output]++;
                ans.push_back(output);
            }
            return;
        }
        if(balance < 0) return;

        if(s[i] == '(') {
            if(removeOpen > 0) solve(s, output, balance, removeOpen-1, removeClose, i+1);
            solve(s, output + s[i], balance+1, removeOpen, removeClose, i+1);
        } else if(s[i] == ')') {
            if(removeClose > 0) solve(s, output, balance, removeOpen, removeClose-1, i+1);
            solve(s, output + s[i], balance-1, removeOpen, removeClose, i+1);
        }
        else solve(s, output + s[i], balance, removeOpen, removeClose, i+1);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<int> removeExtras = checkExtras(s);
        int removeOpen = removeExtras[0];
        int removeClose = removeExtras[1];

        string output = "";
        int balance = 0;
        solve(s, output, balance, removeOpen, removeClose, 0);

        if(ans.size() == 0) return {""};
        return ans;
    }
};