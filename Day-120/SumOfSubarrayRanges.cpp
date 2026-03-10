class Solution {
public:
    void nextMinimum(vector<int>& arr, vector<int>& next) {
        int n = arr.size();
        stack<int> s;
        s.push(n-1);

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

    void prevMinimum(vector<int>& arr, vector<int>& prev) {
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
            }

            s.push(i);
        }
    }

    long long sumOfSubArrayMinimum(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n, -1);
        next[n-1] = n;
        vector<int> prev(n, -1);

        nextMinimum(arr, next);
        prevMinimum(arr, prev);

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long nexti = next[i];
            long long previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            sum += left * right * arr[i];
        }

        return sum;
    }

    void nextMaximum(vector<int>& arr, vector<int>& next) {
        int n = arr.size();
        stack<int> s;
        s.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            if(arr[s.top()] >= arr[i]) next[i] = s.top();
            else {
                while(!s.empty()) {
                    if(arr[s.top()] >= arr[i]) {
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

    void prevMaximum(vector<int>& arr, vector<int>& prev) {
        int n = arr.size();
        stack<int> s;
        s.push(0);

        for(int i = 1; i < n; i++) {
            if(arr[s.top()] > arr[i]) prev[i] = s.top();
            else {
                while(!s.empty()) {
                    if(arr[s.top()] > arr[i]) {
                        prev[i] = s.top();
                        break;
                    }
                    else s.pop();
                }
            }

            s.push(i);
        }
    }

    long long sumOfSubArrayMaximum(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n, -1);
        next[n-1] = n;
        vector<int> prev(n, -1);

        nextMaximum(arr, next);
        prevMaximum(arr, prev);

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long nexti = next[i];
            long long previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            sum += left * right * arr[i];
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long subArrayMinimum = sumOfSubArrayMinimum(nums);
        long long subArrayMaximum = sumOfSubArrayMaximum(nums);

        return subArrayMaximum - subArrayMinimum;
    }
};