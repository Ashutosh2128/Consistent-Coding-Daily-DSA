class Solution {
public:
    int lastIndex(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size() - 1;

        int lastIdx = -1;
        while(s <= e) {
            int mid = s + (e-s) / 2;

            if(nums[mid] == t) {
                lastIdx = mid;
                s = mid+1;
            }
            else if(nums[mid] < t) s = mid+1;
            else e = mid-1;
        }

        return lastIdx;
    }

    int firstIndex(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size() - 1;

        int firstIdx = -1;
        while(s <= e) {
            int mid = s + (e-s) / 2;

            if(nums[mid] == t) {
                firstIdx = mid;
                e = mid-1;
            }
            else if(nums[mid] < t) s = mid+1;
            else e = mid-1;
        }

        return firstIdx;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int first = firstIndex(nums, target);
        int last = lastIndex(nums, target);

        if(first == -1 || last == -1) return {};

        vector<int> ans;
        for(int i = first; i <= last; i++) ans.push_back(i);

        return ans;
    }
};









// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());

//         vector<int> ans;
//         for(int i = 0; i < nums.size(); i++) if(nums[i] == target) ans.push_back(i);

//         return ans;
//     }
// };