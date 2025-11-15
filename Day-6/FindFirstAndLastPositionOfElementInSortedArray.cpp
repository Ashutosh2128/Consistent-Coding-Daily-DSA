class Solution {
public:
    int findFistOcc(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;

        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(arr[mid] == target) {
                ans = mid;
                e = mid - 1;
            }
            else if(arr[mid] < target) s = mid + 1;
            else e = mid - 1;
        }

        return ans;
    }

    int findLastOcc(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;

        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(arr[mid] == target) {
                ans = mid;
                s = mid + 1;
            }
            else if(arr[mid] < target) s = mid + 1;
            else e = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        if(n == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int first = findFistOcc(nums, target);
        int last = findLastOcc(nums, target);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};