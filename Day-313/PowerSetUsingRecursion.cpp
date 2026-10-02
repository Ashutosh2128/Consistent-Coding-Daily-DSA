class Solution {
  public:
    vector<string> ans;
    
    void solve(string& s, string output, int i) {
        if(i >= s.length()) {
            ans.push_back(output);
            return;
        }
        
        // include
        solve(s, output + s[i], i+1);
        
        // exclude
        solve(s, output, i+1);
    }
  
    vector<string> powerSet(string s) {
        string output = "";
        solve(s, output, 0);
        return ans;
    }
};
