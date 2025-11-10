class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        int s = 0;
        int e = arr.size() - 1;
        
        while(s < e) {
            if(arr[s] + arr[e] == target) return true;
            else if(arr[s] + arr[e] > target) e--;
            else s++;
        }
        
        return false;
    }
};


// Brute force TLE Problem
// class Solution {
//   public:
//     bool twoSum(vector<int>& arr, int target) {
//         if(arr.size() == 1) return false;
        
//         for(int i = 0; i < arr.size(); i++) {
//             for(int j = i+1; j < arr.size(); j++) {
//                 if(arr[i] + arr[j] == target) return true;
//             }
//         }
        
//         return false;
//     }
// };