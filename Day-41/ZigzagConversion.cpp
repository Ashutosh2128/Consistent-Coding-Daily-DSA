class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans = "";
        vector<string> zigzag(numRows);

        int i = 0;
        while(i < s.length()) {
            int j = 0;
            while(j < numRows && i < s.length()) {
                zigzag[j++].push_back(s[i++]);
            }

            j = numRows - 2;
            while(j > 0 && i < s.length()) {
                zigzag[j--].push_back(s[i++]);
            }
        }

        for(auto it : zigzag) {
            for(int i = 0; i < it.length(); i++) {
                ans += it[i];
            }
        }

        return ans;
    }
};