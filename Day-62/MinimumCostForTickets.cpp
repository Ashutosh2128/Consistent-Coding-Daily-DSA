    class Solution {
    public:
        int solve(vector<int>& days, vector<int>& costs, int i) {
            if(i >= days.size()) return 0;

            int cost1 = costs[0] + solve(days, costs, i+1);

            int passEnd = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEnd) {
                j++;
            }
            int cost7 = costs[1] + solve(days, costs, j);

            passEnd = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEnd) {
                j++;
            }
            int cost30 = costs[2] + solve(days, costs, j);

            return min(cost1, min(cost7, cost30));
        }

        int mincostTickets(vector<int>& days, vector<int>& costs) {
            return solve(days, costs, 0);
        }
    };