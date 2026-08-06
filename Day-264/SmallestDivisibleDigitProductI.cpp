class Solution {
public:
    int ProductOfDigit(int n) {
        int product = 1;

        while(n) {
            product *= n % 10;
            n /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        while(ProductOfDigit(n) % t != 0) n++;
        return n;
    }
};