class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;
        for(int num : st) {
            if(st.find(num - 1) == st.end()) {
                int curr = num;
                int cnt = 1;

                while(st.find(curr+1) != st.end()) {
                    cnt++;
                    curr = curr+1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};








// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int longest = 1;
//         int curr = 1;

//         for(int i = 0; i < n-1; i++) {
//             if(nums[i+1] == nums[i]) continue;
//             else if(nums[i+1] != nums[i]+1) {
//                 longest = max(longest, curr);
//                 curr = 1;
//             }
//             else curr++;
//         }

//         longest = max(longest, curr);

//         return longest;
//     }
// };