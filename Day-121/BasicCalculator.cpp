class Solution {
public:
    int calculate(string str) {
        long long result = 0;
        long long num = 0;
        long long sign = 1;
        stack<long long> s;

        for(char ch: str) {
            if(ch >= '0' && ch <= '9') num = num * 10 + (ch - '0');
            else if(ch == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            }
            else if(ch == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            }
            else if(ch == '(') {
                s.push(result);
                s.push(sign);
                result = 0;
                sign = 1;
            }
            else if(ch == ')') {
                result += sign * num;
                int sign = s.top();
                s.pop();
                result = s.top() + sign * result;
                s.pop();
                num = 0;
            }
        }

        result += sign * num;
        return result;
    }
};