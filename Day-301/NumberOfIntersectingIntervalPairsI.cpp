class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int intervalCnt = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if((intervals[i][0] >= intervals[j][0] && intervals[i][0] <= intervals[j][1]) ||
                    (intervals[i][1] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) ||
                    (intervals[j][0] >= intervals[i][0] && intervals[j][0] <= intervals[i][1]) ||
                    (intervals[j][1] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]))
                    intervalCnt++;
            }
        }

        return intervalCnt;
    }
};