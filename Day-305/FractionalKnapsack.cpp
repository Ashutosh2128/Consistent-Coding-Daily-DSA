class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<double> unitRatio;
        for(int i = 0; i < wt.size(); i++) unitRatio.push_back((val[i] * 1.0) / wt[i]);
        
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i = 0; i < wt.size(); i++) pq.push({unitRatio[i], {wt[i], val[i]}});
        
        double totalVal = 0;
        while(capacity && !pq.empty()) {
            pair<double, pair<int, int>> top = pq.top();
            pq.pop();
            
            double unitVal = top.first;
            int weight = top.second.first;
            int value = top.second.second;
            
            if(capacity >= weight) {
                // put whole weigth into the knapsack
                totalVal += value;
                capacity -= weight;
            } else {
                // put fraction weight into the knapsack
                totalVal += unitVal * capacity;
                capacity -= capacity;
            }
        }
        
        return totalVal;
    }
};
