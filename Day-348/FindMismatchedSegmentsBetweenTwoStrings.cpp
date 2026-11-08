class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;

        string temp1 = "";
        string temp2 = "";
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] == s2[i]) {
                if(temp1.size() && temp2.size()) {
                    ans.push_back({temp1, temp2});
                    temp1 = "";
                    temp2 = "";
                }
            }
            else {
                temp1.push_back(s1[i]);
                temp2.push_back(s2[i]);
            }
        }

        if(temp1.length()) ans.push_back({temp1, temp2});

        return ans;
    }
};©leetcode