class Solution {
public:
    int findMinHelper(vector<int>& nums) {
        int n = nums.size();
        
        int s = 0;
        int e = n-1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(mid+1 < n && mid-1 >= 0 && nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) return nums[mid];
            else if(nums[mid] > nums[n-1]) s = mid+1;
            else e = mid-1;
        }

        return nums[s];
    }

    int findMin(vector<int>& nums) {
        return findMinHelper(nums);
    }
};





// Required O(N) complexity
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         for(int i = 0; i < nums.size()-1; i++) {
//             if(nums[i] > nums[i+1]) return nums[i+1];
//         }

//         // means array never rotate
//         return nums[0];
//     }
// };