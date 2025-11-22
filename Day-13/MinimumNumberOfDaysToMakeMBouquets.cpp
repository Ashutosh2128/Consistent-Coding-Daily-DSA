class Solution {
public:
    bool isPossibleDay(vector<int>& arr, int m, int k, int day) {
        int count = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) count++;
            else count = 0;

            if(count == k) {
                m--;
                count = 0;
            }
        }

        if(m <= 0) return true;

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * (long long)k > bloomDay.size()) return -1;

        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(minDay <= maxDay) {
            int mid = minDay + (maxDay - minDay) / 2;

            if(isPossibleDay(bloomDay, m, k, mid)) {
                ans = mid;
                maxDay = mid - 1;
            }
            else minDay = mid + 1;
        }

        return ans;
    }
};