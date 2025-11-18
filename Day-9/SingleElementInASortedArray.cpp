//approach -> before one appear element the double appear element starts from even index, but after one appear element the double appear element starts from odd index.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n-1;

        int firstIdx;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(mid-1 >= 0 && nums[mid-1] == nums[mid]) firstIdx = mid - 1;
            else if(mid+1 < n && nums[mid+1] == nums[mid]) firstIdx = mid;
            else return nums[mid];

            if(firstIdx & 1) {
                //odd
                ans = nums[firstIdx];
                e = mid-1;
            }
            else {
                //even
                s = mid+1;
            }
        }

        return ans;
    }
};




// It required O(n) complexity
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int ans = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             ans ^= nums[i];
//         }

//         return ans;
//     }
// };