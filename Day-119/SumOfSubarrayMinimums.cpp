class Solution {
public:
    void nextSmaller(vector<int>& arr, vector<int>& next) {
        int n = arr.size();
        stack<int> s;
        s.push(n - 1);

        for(int i = n-2; i >= 0; i--) {
            if(arr[s.top()] <= arr[i]) next[i] = s.top();
            else {
                while(!s.empty()) {
                    if(arr[s.top()] <= arr[i]) {
                        next[i] = s.top();
                        break;
                    }
                    else s.pop();
                }
                if(s.empty()) next[i] = n;
            }

            s.push(i);
        }
    }

    void prevSmaller(vector<int>& arr, vector<int>& prev) {
        int n = arr.size();
        stack<int> s;
        s.push(0);

        for(int i = 1; i < n; i++) {
            if(arr[s.top()] < arr[i]) prev[i] = s.top();
            else {
                while(!s.empty()) {
                    if(arr[s.top()] < arr[i]) {
                        prev[i] = s.top();
                        break;
                    }
                    else s.pop();
                }
                // if(s.empty()) next[i] = n;
            }

            s.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n, -1);
        next[n-1] = n;
        vector<int> prev(n, -1);

        nextSmaller(arr, next);
        prevSmaller(arr, prev);

        int mod = 1e9 + 7;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            int previ = prev[i];
            int nexti = next[i];
            int left = nexti - i;
            int right = i - previ;

            long long numberOfTimes = (left * right) % mod;
            long long totalTimes = (numberOfTimes * arr[i]) % mod;
            sum = (sum + totalTimes) % mod;
        }

        return sum;
    }
};