string copyStr;

class Solution {
public:
    static bool customCmp(char a, char b) {
        return (copyStr.find(a) < copyStr.find(b));
    }

    string customSortString(string order, string s) {
        copyStr = order;

        sort(s.begin(), s.end(), customCmp);
        return s;
    }
};