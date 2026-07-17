class Solution {
public:
    int solveUsingTab(vector<int>& coins, int amount) {
        // step-1: create dp array
        vector<int> dp(amount+1, -1);

        // step-2: analyse base case and modify dp array
        dp[0] = 0;

        // step-3: check parameter, reverse it, copy paste logic
        for(int amt = 1; amt <= amount; amt++) {
            int minCoin = INT_MAX;
            for(int i = 0; i < coins.size(); i++) {
                int coin = coins[i];

                if(coin <= amt) {
                    int remAmt = amt - coin;
                    int ans = dp[remAmt];

                    if(ans != INT_MAX) {
                        int coinUsed = 1 + ans;
                        minCoin = min(minCoin, coinUsed);
                    }
                }
            }
            
            dp[amt] = minCoin;
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingTab(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};




// class Solution {
// public:
//     int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
//         if(amount == 0) return 0;

//         // step-3: after base case check if answer present in dp array or not
//         if(dp[amount] != -1) return dp[amount];

//         int minCoin = INT_MAX;
//         for(int i = 0; i < coins.size(); i++) {
//             int coin = coins[i];

//             if(coin <= amount) {
//                 int remAmt = amount - coin;
//                 int ans = solveUsingMem(coins, remAmt, dp);

//                 if(ans != INT_MAX) {
//                     int coinUsed = 1 + ans;
//                     minCoin = min(minCoin, coinUsed);
//                 }
//             }
//         }

//         //step-2: Store ans in dp and return
//         dp[amount] = minCoin;
//         return dp[amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         // step-1: create dp array and pass it to the function
//         vector<int> dp(amount+1, -1);
//         int ans = solveUsingMem(coins, amount, dp);
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
// };





// class Solution {
// public:
//     int solve(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;

//         int minCoin = INT_MAX;
//         for(int i = 0; i < coins.size(); i++) {
//             int coin = coins[i];

//             if(coin <= amount) {
//                 int remAmt = amount - coin;
//                 int ans = solve(coins, remAmt);

//                 if(ans != INT_MAX) {
//                     int coinUsed = 1 + ans;
//                     minCoin = min(minCoin, coinUsed);
//                 }
//             }
//         }

//         return minCoin;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solve(coins, amount);
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
// };