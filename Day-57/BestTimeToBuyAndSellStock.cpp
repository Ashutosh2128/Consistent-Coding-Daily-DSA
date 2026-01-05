class Solution {
public:
    void solve(vector<int>& prices, int i, int& maxProfit, int& minPrice) {
        //base case
        if(i == prices.size()) return;

        minPrice = min(minPrice, prices[i]);
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);

        solve(prices, i+1, maxProfit, minPrice);
    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;

        solve(prices, 0, maxProfit, minPrice);

        return maxProfit;
    }
};





//Got TLE
// class Solution {
// public:
//     void solve(vector<int>& prices, int i, int j, int& maxProfit) {
//         if(i == prices.size() - 1) return;

//         int buy = i;
//         for(int sell = j; sell < prices.size(); sell++) {
//             int profit = prices[sell] - prices[buy];
//             maxProfit = max(profit, maxProfit);
//         }

//         solve(prices, i+1, i+2, maxProfit);
//     }

//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;
//         solve(prices, 0, 1, maxProfit);

//         return maxProfit;
//     }
// };