class Solution {
public:
    vector<string> ans;

    void solve(string output, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(output);
        }

        if(open) solve(output + '(', open-1, close);
        if(close > open) (solve(output + ')', open, close-1));
    }

    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string output = "";
        solve(output, open, close);

        return ans;
    }
};