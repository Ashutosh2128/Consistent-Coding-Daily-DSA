class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int totalSize = rowSize * colSize;

        int s = 0;
        int e = totalSize - 1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            int row = mid / colSize;
            int col = mid % colSize;

            if(matrix[row][col] == target) return true;
            else if(target > matrix[row][col]) s = mid + 1;
            else e = mid - 1;
        }

        return false;
    }
};







// It required O(m * log n) complexity
// class Solution {
// public:
//     bool binarySearch(vector<int>& v, int target) {
//         int n = v.size();

//         int s = 0;
//         int e = n - 1;

//         while(s <= e) {
//             int mid = s + (e - s) / 2;

//             if(v[mid] == target) return true;
//             else if(target > v[mid]) s = mid + 1;
//             else e = mid - 1;
//         }

//         return false;
//     }

//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int rowSize = matrix.size();
//         int colSize = matrix[0].size();

//         for(int i = 0; i < rowSize; i++) {
//             bool ans = binarySearch(matrix[i], target);

//             if(ans) return ans;
//         }

//         return false;
//     }
// };