class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int mask = 1 << k;
        return mask | n;
    }
};
