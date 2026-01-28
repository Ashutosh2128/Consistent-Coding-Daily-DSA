//In place merge sort
class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e) {
        int totalLen = e - s + 1;
        int gap = totalLen / 2 + totalLen % 2; //ceil(totalLen / 2)
        // int gap = ceil(totalLen / 2);

        while(gap) {
            int i = s;
            int j = i + gap;

            while(j <= e) {
                if(nums[i] > nums[j]) swap(nums[i], nums[j]);
                i++; j++;
            }

            // gap = gap <= 1 ? 0 : ceil(gap / 2);
            gap = gap <= 1 ? 0 : gap / 2 + gap % 2;
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if(s >= e) return;

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);

        merge(nums, s, mid, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};








// Merge Sort with extra space
// class Solution {
// public:
//     void merge(vector<int>& nums, vector<int>& temp, int s, int mid, int e) {
//         int i = s;
//         int j = mid + 1;
//         int k = s;

//         while(i <= mid && j <= e) {
//             if(nums[i] <= nums[j]) temp[k++] = nums[i++];
//             else temp[k++] = nums[j++];
//         }

//         while(i <= mid)
//             temp[k++] = nums[i++];

//         while(j <= e)
//             temp[k++] = nums[j++];

//         k = s;
//         while(s <= e) {
//             nums[s++] = temp[k++];
//         }
//     }

//     void mergeSort(vector<int>& nums, vector<int>& temp, int s, int e) {
//         if(s >= e) return;

//         int mid = s + (e - s) / 2;

//         mergeSort(nums, temp, s, mid);
//         mergeSort(nums, temp, mid+1, e);

//         merge(nums, temp, s, mid, e); 
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         vector<int> temp(nums.size(), 0);

//         mergeSort(nums, temp, 0, nums.size() - 1);

//         return nums;
//     }
// };