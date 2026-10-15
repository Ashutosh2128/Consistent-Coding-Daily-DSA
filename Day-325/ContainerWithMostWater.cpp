class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVal = INT_MIN;

        int i = 0;
        int j = height.size()-1;

        while(i < j) {
            maxVal = max(maxVal, (j - i) * min(height[i], height[j]));
            height[i] <= height[j] ? i++ : j--;
        }

        return maxVal;
    }
};