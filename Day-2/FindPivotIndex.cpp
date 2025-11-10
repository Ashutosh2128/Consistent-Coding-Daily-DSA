class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);

        for(int i = 0; i < n; i++) {
            if(i == 0)
                leftSum[i] = 0;
            else
                leftSum[i] = nums[i-1] + leftSum[i-1];
        }

        for(int i = n-1; i >= 0; i--) {
            if(i == n-1)
                rightSum[i] = 0;
            else 
                rightSum[i] = nums[i+1] + rightSum[i+1];
        }

        for(int i = 0; i < n; i++) {
            if(leftSum[i] == rightSum[i]) return i;
        }

        return -1;
    }
};



// Brute force - required O(n^2) complexity
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++) {
//             int leftSum = 0;
//             int rightSum = 0;

//             for(int left = i - 1; left >= 0; left--) {
//                 leftSum += nums[left];
//             }

//             for(int right = i + 1; right < nums.size(); right++) {
//                 rightSum += nums[right];
//             }

//             if(leftSum == rightSum) return i;
//         }

//         return -1;
//     }
// };