class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n-1;

        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(mid+1 < n && nums[mid] < nums[mid+1]) s = mid + 1;
            else {
                ans = mid;
                e = mid - 1;
            }
        }

        return ans;
    }
};