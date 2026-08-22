class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        int nCpy = n;
        while(nCpy) {
            int digit = nCpy % 10;

            sum += digit;
            product *= digit;

            nCpy /= 10;
        }

        return n % (sum + product) ? false : true;
    }
};