class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        sort(logs.begin(), logs.end(), cmp);

        vector<pair<int, int>> q;
        for(int i = 0; i < m; i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        vector<int> ans(m);
        int left = 0;
        int right = 0;
        int active = 0;
        unordered_map<int, int> freq;

        for(auto [time, idx] : q) {
            int start = time - x;
            int end = time;

            while(right < logs.size() && logs[right][1] <= end) {
                int server = logs[right][0];

                if(freq[server] == 0) active++;

                freq[server]++;
                right++;
            }

            while(left < right && logs[left][1] < start) {
                int server = logs[left][0];
                freq[server]--;

                if(freq[server] == 0) active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};








// Brute Force -> Giving TLE
// class Solution {
// public:
//     vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
//         vector<int> ans;
//         for(int query : queries) {
//             vector<bool> vis(n+1, 0);
//             int start = query - x;
//             int end = query;

//             for(auto v : logs) {
//                 if(v[1] >= start && v[1] <= end) vis[v[0]] = 1;
//             }

//             int count = 0;
//             for(int i = 1; i <= n; i++) if(!vis[i]) count++;

//             ans.push_back(count);
//         }

//         return ans;
//     }
// };