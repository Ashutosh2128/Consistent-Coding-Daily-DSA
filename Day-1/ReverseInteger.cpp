class Solution {
public:
    int reverse(int x) {
        if(x <= INT_MIN) return 0;

        int rev = 0;
        bool isNegative = false;

        if(x < 0) {
            isNegative = true;
            x = -x;
        }

        while(x > 0) {
            if(rev > INT_MAX / 10) return 0;
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }

        return isNegative ? -rev : rev;
    }
};