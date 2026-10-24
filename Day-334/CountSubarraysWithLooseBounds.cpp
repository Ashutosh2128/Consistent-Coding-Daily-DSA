class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int start = 0;
        long long count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) start = i + 1;
            else count += i - start + 1;
        }

        return count;
    }
};








// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         int n = nums.size();
//         long long count = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 if(nums[j] >= minK && nums[j] <= maxK) count++;
//                 else break;
//             } 
//         }

//         return count;
//     }
// };