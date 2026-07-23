class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        
        int s = 0;
        int l = n-1;
        
        for(int i = 0; i < n-1; i++) {
            if(arr[i] > arr[i+1]) {
                s = i+1;
                l = i;
                break;
            }
        }
        
        if(s == 0 && l == n-1) {
            while(s < l) {
                int sum = arr[s] + arr[l];
                if(sum == target) return true;
                else if(sum > target) l--;
                else s++;
            }
        }
        else {
            // search space 1 - from 0 to l
            int i = 0;
            int j = l;
            while(i < j) {
                int sum = arr[i] + arr[j];
                if(sum == target) return true;
                else if(sum > target) j--;
                else i++;
            }
            
            // search space 2 - from s to n-1
            i = s;
            j = n-1;
            while(i < j) {
                int sum = arr[i] + arr[j];
                if(sum == target) return true;
                else if(sum > target) j--;
                else i++;
            }
            
            // search space 3 - from s to l
            while(s < n && l >= 0) {
                int sum = arr[s] + arr[l];
                if(sum == target) return true;
                else if(sum > target) l--;
                else s++;
            }
        }
        
        return false;
    }
};