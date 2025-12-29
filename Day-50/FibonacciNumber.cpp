class Solution {
public:
    // int fibonacci(int n) {
    //     if(n == 1 || n == 2) return 1;

    //     int first = 1;
    //     int second = 1;
    //     int fibNum = 0;

    //     for(int i = 3; i <= n; i++) {
    //         fibNum = first + second;
    //         first = second;
    //         second = fibNum;
    //     }

    //     return fibNum;
    // }

    int fibonacci(int n) {
        if(n == 0) return n;
        if(n == 1 || n == 2) return 1;

        return fibonacci(n-1) + fibonacci(n-2);
    }

    int fib(int n) {
        return fibonacci(n);
    }
};