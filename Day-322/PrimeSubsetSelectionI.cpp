class Solution {
public:
    void storePrime(int n, vector<int>& prime) {
        if(n == 0 || n == 1) return;

        vector<bool> checkPrime(n+1, true);
        checkPrime[0] = checkPrime[1] = 0;

        for(int i = 2; i <= n; i++) {
            if(checkPrime[i]) {
                prime.push_back(i);

                int j = i * 2;
                while(j <= n) {
                    checkPrime[j] = false;
                    j += i;
                }
            } 
        }
    }
    
    vector<int> maxPrimes(int n, int s) {
        if(s == 1) return {};

        vector<int> prime;
        storePrime(n, prime);

        long long sum = accumulate(prime.begin(), prime.end(), 0LL);

        int i = prime.size() - 1;
        while(1) {
            if(sum > s) {
                sum -= prime[i];
                prime.pop_back();
                i--;
            }
            else break;
        }

        return prime;
    }
};