class Solution {
public:
    void solve(vector<string>& ans, string output, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        if(open) {
            output.push_back('(');
            solve(ans, output, open-1, close);
            //backtrack
            output.pop_back();
        }

        if(close > open) { //Remember: Here is the trick I get stuck by doing, if(close)
            output.push_back(')');
            solve(ans, output, open, close-1);
            //backtrack
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";

        solve(ans, output, n, n);

        return ans;
    }
};