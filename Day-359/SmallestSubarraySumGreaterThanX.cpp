class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        
        for(int right = 0; right < n; right++) {
            sum += arr[right];
            
            while(left <= right && sum > x) {
                minLen = min(minLen, (right - left + 1));
                sum -= arr[left++];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};