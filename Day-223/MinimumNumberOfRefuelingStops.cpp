class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int fuel = startFuel;
        int i = 0;
        priority_queue<pair<int, int>> pq;

        while(1) {
            while(i < stations.size()) {
                if(stations[i][0] <= dist + fuel) pq.push({stations[i][1], stations[i][0]});
                else break;
                i++;
            }   

            dist += fuel;
            fuel = 0;

            if(dist >= target) break;

            if(pq.empty()) {
                stops = -1;
                break;
            }

            auto [f, d] = pq.top();
            pq.pop();
            fuel = dist - d + f;
            dist = d;
            stops++;
        }

        return stops;
    }
};