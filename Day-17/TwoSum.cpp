class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int require = target - nums[i];

            if(mp.find(require) != mp.end()) {
                return {mp[require], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};










//required O(n^2) TC and O(1) SC
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();

//         vector<int> v;

//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 if(nums[i] + nums[j] == target) {
//                     v.push_back(i);
//                     v.push_back(j);
//                     break;
//                 }
//             }
//         }

//         return v;
//     }
// };