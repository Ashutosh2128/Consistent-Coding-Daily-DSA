class Solution {
public:
    int getPivotIndex(vector<int>& arr) {
        int n = arr.size();

        int s = 0;
        int e = n - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if((mid + 1 < n) && arr[mid] > arr[mid + 1]) return mid;
            else if((mid - 1 >= 0) && arr[mid - 1] > arr[mid]) return mid - 1;
            else if(arr[s] > arr[mid]) e = mid - 1;
            else s = mid + 1;
        }

        return s;
    }

    int binarySearch(int s, int e, vector<int>& arr, int target) {
        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(target == arr[mid]) return mid;
            else if(target < arr[mid]) e = mid - 1;
            else s = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);

        int n = nums.size();

        if(target == nums[pivotIndex]) return pivotIndex;
        else if(target >= nums[0] && target <= nums[pivotIndex]) return binarySearch(0, pivotIndex, nums, target);
        else if(target < nums[0] && target <= nums[n-1]) return binarySearch(pivotIndex + 1, n - 1, nums, target);

        return -1;
    }
};