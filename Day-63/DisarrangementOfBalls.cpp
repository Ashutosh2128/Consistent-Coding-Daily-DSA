// User function Template for C++

class Solution {
  public:
    int solve(int n) {
        if(n == 1) return 0;
        
        if(n == 2) return 1;
        
        return (n-1) * (solve(n-1) + solve(n-2));
    }
  
    int countDer(int n) {
        return solve(n);
    }
};