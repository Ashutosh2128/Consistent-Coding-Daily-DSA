class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int windowSum = arr[0];
        
        while(right < n) {
            int target = arr[right];
            // calculate cost = target * windowSize + windowSum
            int cost = target * (right - left + 1) - windowSum;
            
            if(cost <= k) {
                maxFreq = max(maxFreq, right - left + 1);
                // windowSum += arr[++right]; // This can make create error during boundary check when right is n so correct way down below
                right++;
                if(right < n) windowSum += arr[right];
            }
            else windowSum -= arr[left++];
        }
        
        return maxFreq;
    }
};