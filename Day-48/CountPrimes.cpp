//Approach: Sieve of Eratosthense
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;
        int count = 0;

        for(int i = 2; i < n; i++) {
            if(prime[i] == true) {
                count++;

                int j = i * 2;
                while(j < n) {
                    prime[j] = false;
                    j += i;
                }
            }
        }

        return count;
    }
};





// TLE at test case 20
// class Solution {
// public:
//     bool isPrime(int n) {
//         int sqrtN = sqrt(n);

//         for(int i = 2; i <= sqrtN; i++) {
//             if(n % i == 0) return false;
//         }

//         return true;
//     }

//     int countPrimes(int n) {
//         int count = 0;

//         for(int i = 2; i < n; i++) {
//             if(isPrime(i)) count++;
//         }

//         return count;
//     }
// };





// Got TLE at test case 17
// class Solution {
// public:
//     bool isPrime(int n) {
//         for(int i = 2; i < n; i++) {
//             if(n % i == 0) return false;
//         }

//         return true;
//     }

//     int countPrimes(int n) {
//         int count = 0;

//         for(int i = 2; i < n; i++) {
//             if(isPrime(i)) count++;
//         }

//         return count;
//     }
// };