class Solution {
  public:
    bool isPossiblePages(vector<int>& arr, int k, int pages) {
        int totalPages = 0;
        int student = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > pages) return false;
            
            if(totalPages + arr[i] <= pages) {
                totalPages += arr[i];
            }
            else {
                student++;
                totalPages = arr[i];
            }
        }
        
        if(student <= k) return true;
        return false;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(n < k) return -1;
        
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        
        int s = 1;
        int e = sum;
        
        while(s <= e) {
            int mid = s + ((e - s) >> 1);
            
            if(isPossiblePages(arr, k, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        
        return ans;
    }
};