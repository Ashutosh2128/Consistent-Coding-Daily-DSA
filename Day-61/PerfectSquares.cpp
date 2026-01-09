class Solution {
public:
    int solve(int n) {
        //base case
        if(n == 0) return 0;

        int i = 1;
        int end = sqrt(n);
        int finalAns = INT_MAX;

        while(i <= end) {
            int square = i * i;
            int ans = 1 + solve(n - square);
            if(ans < finalAns) finalAns = ans;
            i++;
        }
    
        return finalAns;
    }

    int numSquares(int n) {
        return solve(n);
    }
};