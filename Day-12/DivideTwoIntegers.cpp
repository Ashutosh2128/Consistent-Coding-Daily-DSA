class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool ans_pos_sign = true; // means positive

        if(dividend < 0 && divisor > 0) ans_pos_sign = false; // means negative ans will produce
        if(dividend > 0 && divisor < 0) ans_pos_sign = false; //means negative ans will produce

        long long int newDividend = abs((long long int)dividend);
        long long int newDivisor = abs((long long int)divisor);

        long long int s = 1;
        long long int e = newDividend;

        long long int ans = 0;

        while(s <= e) {
            long long int mid = s + (e - s) / 2;

            if(newDivisor * mid <= newDividend) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }

        if(ans_pos_sign) return ans;

        return -ans;
    }
};