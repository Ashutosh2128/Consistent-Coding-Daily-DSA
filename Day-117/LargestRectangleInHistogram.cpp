class Solution {
public:
    void nextSmaller(vector<int>& arr, vector<int>& next) {
        int n = arr.size();
        stack<int> s;
        s.push(n-1);

        for(int i = n - 2; i >= 0; i--) {
            if(arr[s.top()] < arr[i]) next[i] = s.top();
            else {
                while(!s.empty()) {
                    if(arr[s.top()] < arr[i]) {
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
                // if(s.empty()) prev[i] = -1; //No need for this line
            }

            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n, -1);
        vector<int> prev(n, -1);

        next[n-1] = n;
        //no need to set prev[0] = -1, it is already -1.

        nextSmaller(heights, next);
        prevSmaller(heights, prev);

        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++) {
            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;
            int area = length * breadth;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};