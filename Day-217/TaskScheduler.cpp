class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char ch : tasks) mp[ch]++;

        priority_queue<pair<int, char>> pq;
        for(auto [ch, freq] : mp) pq.push({freq, ch});

        int time = 0;
        while(!pq.empty()) {
            int size = pq.size();
            int cycle = n+1;
            vector<pair<int, char>> v;

            while(size--) {
                auto [freq, ch] = pq.top();
                pq.pop();

                freq--;
                cycle--;
                time++;

                if(freq) v.push_back({freq, ch});
                if(cycle == 0) break;
            }

            if(!v.empty() && cycle > 0) time += cycle;
            for(auto[freq, ch] : v) pq.push({freq, ch});
        }

        return time;
    }
};