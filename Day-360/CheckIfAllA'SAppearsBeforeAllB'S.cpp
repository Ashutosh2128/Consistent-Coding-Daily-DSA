class Solution {
public:
    bool checkString(string s) {
        bool a = false;
        bool b = false;

        for(char ch : s) {
            if(ch == 'a') if(b) return false;
            if(ch == 'b') b = true;
        }

        return true;
    }
};