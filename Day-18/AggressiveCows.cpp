class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int dist) {
        int cow = 1;
        int pos = arr[0];
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - pos >= dist) {
                cow++;
                pos = arr[i];
            }
            if(cow == k) return true;
        }
        
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int ans = -1;
        int s = 0;
        int e = stalls[stalls.size() - 1] - stalls[0]; // highest minimum distance if cow is 2
        
        while(s <= e) {
            int mid = s + ((e - s) >> 2);
            
            if(isPossible(stalls, k, mid)) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        
        return ans;
    }
};