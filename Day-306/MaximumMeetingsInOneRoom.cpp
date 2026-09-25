class Solution {
  public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
  
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<vector<int>> time;
        for(int i = 0; i < s.size(); i++) time.push_back({s[i], f[i], i});
        
        sort(time.begin(), time.end(), cmp);
        
        vector<int> ans;
        ans.push_back(time[0][2]+1);
        int prevStart = time[0][0];
        int prevEnd = time[0][1];
        
        for(int i = 1; i < s.size(); i++) {
            int currStart = time[i][0];
            int currEnd = time[i][1];
            if(currStart > prevEnd) {
                ans.push_back(time[i][2] + 1);
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};