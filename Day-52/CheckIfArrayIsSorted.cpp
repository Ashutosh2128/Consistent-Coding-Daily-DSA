class Solution {
  public:
    bool checkSorted(vector<int>& arr, int idx) {
        if(idx == arr.size() - 1) return true;
        
        if(arr[idx] <= arr[idx+1]) return checkSorted(arr, idx+1);
        return false;
    }
  
    bool isSorted(vector<int>& arr) {
        return checkSorted(arr, 0);
    }
};