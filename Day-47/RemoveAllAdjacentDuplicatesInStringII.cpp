class Solution {
public:
    bool checkLastK_1(string& ans, char& ch, int k_1) {
        int it = ans.size() - 1;
        for(int i = 0; i < k_1; i++) {
            if(ans[it] != ch) return false;
            it--;
        }

        return true;
    }

    string removeDuplicates(string s, int k) {
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            if(ans.length() < k-1) ans.push_back(s[i]);
            else {
                //check wheather last k-1 element same or not with the ith element
                if(checkLastK_1(ans, s[i], k-1)) {
                    for(int j = 0; j < k-1; j++) {
                        ans.pop_back();
                    }
                }
                else ans.push_back(s[i]);
            }
        }

        return ans;
    }
};