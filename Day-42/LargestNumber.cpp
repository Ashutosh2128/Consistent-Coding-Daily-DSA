class Solution {
public:
    static bool cmp(string a, string b) {
        string s1 = a + b;
        string s2 = b + a;
        return s1 > s2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str;

        for(auto num : nums) {
            str.push_back(to_string(num));
        }

        sort(str.begin(), str.end(), cmp);
        if(str[0] == "0") return "0"; //test case 232 not passed that's why need this condition

        string ans = "";
        for(auto i : str) {
            ans += i;
        }

        return ans;
    }
};