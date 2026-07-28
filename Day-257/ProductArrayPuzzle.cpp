class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        
        int product = 1;
        vector<int> prefix(n);
        for(int i = 0; i < n; i++) {
            prefix[i] = product;
            product *= arr[i];
        }
        
        product = 1;
        vector<int> suffix(n);
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = product;
            product *= arr[i];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(prefix[i] * suffix[i]);
        
        return ans;
    }
};







// Failed if any array element have 0
// class Solution {
//   public:
//     vector<int> productExceptSelf(vector<int>& arr) {
//         int product = 1;
//         for(int i : arr) product *= i;
        
//         vector<int> ans;
//         for(int i : arr) ans.push_back(product / i);
        
//         return ans;
//     }
// };