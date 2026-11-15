class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int prefix = 0;
        int even = 1;
        int odd = 0;
        int ans = 0;

        for(int it : arr) {
            prefix += it;

            if(prefix & 1) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};