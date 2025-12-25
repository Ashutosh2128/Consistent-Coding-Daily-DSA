class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int zero = 0;
        int maxLen = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == 0) zero++;

            if(zero > k) {
                if(nums[i] == 0) zero--;
                i++;
            }

            if(zero <= k) 
                maxLen = max(maxLen, (j - i + 1));
        }

        return maxLen;
    }
};






// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int i = 0;
//         int zero = 0;
//         int maxLen = 0;

//         for(int j = 0; j < nums.size(); j++) {
//             if(nums[j] == 0) zero++;

//             while(zero > k) {
//                 if(nums[i] == 0) zero--;
//                 i++;
//             }

//             maxLen = max(maxLen, (j - i + 1));
//         }

//         return maxLen;
//     }
// };





// Got TLE at test case - 48
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLen = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             int zeroCount = 0;

//             for(int j = i; j < nums.size(); j++) {
//                 if(nums[j] == 0) zeroCount++;

//                 if(zeroCount <= k) maxLen = max(maxLen, (j-i+1));
//                 else break;
//             }
//         }

//         return maxLen;
//     }
// };