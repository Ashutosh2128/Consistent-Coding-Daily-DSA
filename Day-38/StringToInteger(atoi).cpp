class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1; //means positive
        int i = 0;

        while(s[i] == ' ') i++;

        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = s[i] == '+' ? 1 : -1; //here determine sign
            i++;
        }

        while(i < s.size() && isdigit(s[i])) {
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] > '7')) {
                if(sign == -1) return INT_MIN;
                else return INT_MAX;
            }
                
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return ans * sign;
    }
};