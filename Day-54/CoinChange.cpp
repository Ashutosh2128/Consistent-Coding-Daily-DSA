class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int minCoins = INT_MAX;

        for(int i = 0; i < coins.size(); i++) {
            int coin = coins[i];

            if(coin <= amount) {
                int ans = solve(coins, amount - coin);

                if(ans != INT_MAX) {
                    int coinUsed = 1 + ans;
                    minCoins = min(minCoins, coinUsed);
                }
            }
        }

        return minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};