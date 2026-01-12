class Solution {
  public:
    int countWays(int n, int k) {
        if(n == 1) return k;
        if(n == 2) return k + k * (k-1);
        
        return (k-1) * (countWays(n-1, k) + countWays(n-2, k));
    }
};