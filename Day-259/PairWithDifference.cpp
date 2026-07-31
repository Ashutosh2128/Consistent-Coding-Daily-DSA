class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = 1;
        while(j < arr.size()) {
            if(i == j) {
                j++;
                continue;
            }
            int diff = arr[j] - arr[i];
            if(diff == x) return true;
            else if(diff < x) j++;
            else i++;
        }
        
        return false;
    }
};
