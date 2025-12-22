class Solution {
public:
    int convertToMins(string& time) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));

        return 60 * hour + min;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;

        for(auto time : timePoints)
            times.push_back((convertToMins(time)));

        sort(times.begin(), times.end());

        int diff = INT_MAX;
        for(int i = 0; i < times.size() - 1; i++) {
            diff = min(diff, (times[i+1] - times[i]));
        }

        int lastDiff = min(diff, (times[0] + 1440 - times[times.size() - 1]));

        return lastDiff;
    }
};