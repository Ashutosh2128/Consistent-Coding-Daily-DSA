class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod = 1000000007;
        int bits[32] = {0};

        for(int& num : nums) 
            for(int b = 0; b < 32; b++) 
                if(num & (1 << b)) bits[b]++;

        long ans = 0;

        for(int i = 0; i < k; i++) {
            long num = 0;

            for(int b = 0; b < 32; b++) {
                if(bits[b]) {
                    num = num | (1L << b);
                    bits[b]--;
                }
            }

            ans = (ans + num * num) % mod;
        }

        return (int)ans;            
    }
};