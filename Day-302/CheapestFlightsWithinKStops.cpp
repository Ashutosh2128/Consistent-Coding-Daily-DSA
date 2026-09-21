class Solution {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto& flight : flights) adjList[flight[0]].push_back({flight[1], flight[2]});

        // {cost, city, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<int> vis(n, INT_MAX);

        while(!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int cost = top[0];
            int city = top[1];
            int stops = top[2];

            if(city == dst) return cost;

            if(stops > k) continue;

            if(vis[city] != INT_MAX && vis[city] < stops) continue;

            vis[city] = min(vis[city], stops);

            for(pair<int, int> nbr : adjList[city]) {
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost + price, nextCity, stops+1});
            }
        }

        return -1;
    }
};