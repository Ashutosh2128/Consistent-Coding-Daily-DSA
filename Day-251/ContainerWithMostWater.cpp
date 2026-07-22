class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maximum = INT_MIN;

        int i = 0;
        int j = n-1;
        while(i < j) {
            maximum = max(maximum, (j-i)*min(height[i], height[j]));
            height[i] <= height[j] ? i++ : j--;
        }

        return maximum;
    }
};




// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int maximum = INT_MIN;

//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 maximum = max(maximum, (j-i)*min(height[i], height[j]));
//             }
//         }

//         return maximum;
//     }
// };