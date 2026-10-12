class Solution {
public:
    bool threeFibonacciSum(int n) {
        int i = 0;
        int j = 1;

        while(true) {
            int sum = i + j;
            if(sum + sum == n) return true;
            if(sum + sum > n) break;

            i = j;
            j = sum;
        }

        return false;
    }
};