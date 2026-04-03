class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {
            if(balance + gas[i] < cost[i]) {
                deficit += cost[i] - (gas[i] + balance);
                balance = 0;
                start = i+1;
            }
            else balance += gas[i] - cost[i];
        }

        if(balance - deficit >= 0) return start;
        return -1;
    }
};