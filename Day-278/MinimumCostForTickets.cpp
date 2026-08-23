class Solution {
public:
    int solveUsingTab(vector<int>& days, vector<int>& costs, int i = 0) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for(int i = n-1; i >= 0; i--) {
            int cost1 = costs[0] + dp[i+1];

            int passEnds = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEnds) j++;
            int cost7 = costs[1] + dp[j];

            passEnds = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEnds) j++;
            int cost30 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost7, cost30));
        }

        
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solveUsingTab(days, costs);
    }
};







// class Solution {
// public:
//     int solveUsingMem(vector<int>& days, vector<int>& costs, vector<int>& dp, int i = 0) {
//         if(i >= days.size()) return 0;

//         if(dp[i] != -1) return dp[i];

//         int cost1 = costs[0] + solveUsingMem(days, costs, dp, i+1);

//         int passEnds = days[i] + 7 - 1;
//         int j = i;
//         while(j < days.size() && days[j] <= passEnds) j++;
//         int cost7 = costs[1] + solveUsingMem(days, costs, dp, j);

//         passEnds = days[i] + 30 - 1;
//         j = i;
//         while(j < days.size() && days[j] <= passEnds) j++;
//         int cost30 = costs[2] + solveUsingMem(days, costs, dp, j);

//         dp[i] = min(cost1, min(cost7, cost30));
//         return dp[i];
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         vector<int> dp(days.size() + 1, -1);
//         return solveUsingMem(days, costs, dp);
//     }
// };









// class Solution {
// public:
//     int solveUsingRec(vector<int>& days, vector<int>& costs, int i = 0) {
//         if(i >= days.size()) return 0;

//         int cost1 = costs[0] + solveUsingRec(days, costs, i+1);

//         int passEnds = days[i] + 7 - 1;
//         int j = i;
//         while(j < days.size() && days[j] <= passEnds) j++;
//         int cost7 = costs[1] + solveUsingRec(days, costs, j);

//         passEnds = days[i] + 30 - 1;
//         j = i;
//         while(j < days.size() && days[j] <= passEnds) j++;
//         int cost30 = costs[2] + solveUsingRec(days, costs, j);

//         int ans = min(cost1, min(cost7, cost30));
//         return ans;
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return solveUsingRec(days, costs);
//     }
// };