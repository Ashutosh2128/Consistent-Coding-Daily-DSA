class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);

            if(nums[index] >= 0) nums[index] *= -1;
            else return index;
        }

        return -1;
    }
};






//used O(nlogn) due to sort function
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int s = 0;
//         int e = nums.size() - 1;

//         int ans = -1;

//         while(s <= e) {
//             int mid = s + (e - s) / 2;

//             if(nums[mid] - mid >= 1) {
//                 //possible answer
//                 ans = nums[mid];
//                 s = mid + 1;
//             }
//             else e = mid - 1;
//         }

//         return ans;
//     }
// };