class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % 2 != 0) return false; // Incase of odd number of element all pairs cann't be possible
        
        unordered_map<int, int> freq;
        for(const int& it : arr) freq[it % k]++;
        
        // Handling even k mid element
        int mid = -1;
        if(k % 2 == 0) {
            //even
            mid = k / 2;
            if(freq[mid] % 2 != 0) return false;
        }
        
        // Handling 0
        if(freq[0] % 2 != 0) return false;
        
        for(int r = 1; r <= (k-1)/2; r++) if(freq[r] != freq[k-r]) return false;
        
        return true;
    }
};



















// class Solution {
//   public:
//     bool canPair(vector<int> &arr, int k) {
//         int n = arr.size();
//         if(n % 2 != 0) return false; // Incase of odd number of element all pairs cann't be possible
        
//         vector<int> reminder;
//         for(const int& it : arr) reminder.push_back(it % k);
        
//         unordered_map<int, int> freq;
//         for(const int& it : reminder) freq[it]++;
        
//         // Handling even k mid element
//         int mid = -1;
//         if(k % 2 == 0) {
//             //even
//             mid = k / 2;
//             if(freq[mid] % 2 != 0) return false;
//         }
        
//         // Handling 0
//         if(freq[0] % 2 != 0) return false;
        
//         for(int r = 1; r < k; r++) {
//             if(r == mid) continue;
            
//             int subtract = k - r;
//             if(freq[r] != freq[subtract]) return false;
//         }
        
//         return true;
//     }
// };