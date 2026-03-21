class Solution {
public:
    void nextSmaller(vector<int>& v, vector<int>& next) {
        int n = v.size();
        stack<int> st;
        st.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            if(v[st.top()] < v[i]) next[i] = st.top();
            else {
                while(!st.empty()) {
                    if(v[st.top()] < v[i]) {
                        next[i] = st.top();
                        break;
                    }
                    else st.pop();
                }
                if(st.empty()) next[i] = n;
            }

            st.push(i);
        }
    }

    void prevSmaller(vector<int>& v, vector<int>& prev) {
        int n = v.size();
        stack<int> st;
        st.push(0);

        for(int i = 1; i < n; i++) {
            if(v[st.top()] < v[i]) prev[i] = st.top();
            else {
                while(!st.empty()) {
                    if(v[st.top()] < v[i]) {
                        prev[i] = st.top();
                        break;
                    }
                    else st.pop();
                }
            }

            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& v) {
        int n = v.size();

        vector<int> prev(n, -1);
        vector<int> next(n, -1);
        next[n-1] = n;

        nextSmaller(v, next);
        prevSmaller(v, prev);

        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++) {
            int length = v[i];
            int breadth = next[i] - prev[i] - 1;
            int area = length * breadth;
            maxArea = max(maxArea, area);
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int i = 0; i < rowSize; i++) {
            vector<int> t;
            for(int j = 0; j < colSize; j++) {
                t.push_back(matrix[i][j] - '0');
            }

            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for(int i = 1; i < rowSize; i++) {
            for(int j = 0; j < colSize; j++) {
                if(v[i][j]) v[i][j] += v[i-1][j];
            }

            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};