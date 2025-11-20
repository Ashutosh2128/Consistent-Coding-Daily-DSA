class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) candidate = nums[i];

            if(nums[i] == candidate) count++;
            else count--;
        }

        return candidate;
    }
};







// Require O(nlogn) complexity
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         return nums[nums.size()/2];
//     }
// };





// Require O(n) time with space. Which I have solved
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> mp;
//         int majorityCount;

//         for(auto i: nums) {
//             mp[i]++;
//         }

//         for(auto m: mp) {
//             if((m.second) > (n/2)) majorityCount = m.first;
//         }

//         return majorityCount;
//     }
// };