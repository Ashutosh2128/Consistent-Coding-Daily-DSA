class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int product = 1;
        bool allNegative = false;
        int i = 0;
        int j = n-1;
        
        // Here we have to handle 2 case
        // case - 1 : all elements are negative and k is odd
        // case - 2: remaining all cases
        
        if(k & 1) {
            product *= arr[j];
            if(arr[j] < 0) allNegative = true;
            k--;
            j--;
        }
        
        while(k) {
            if(allNegative) {
                product *= arr[j--];
                k--;
            }
            else {
                int left = arr[i] * arr[i+1];
                int right = arr[j] * arr[j-1];
                if(left > right) {
                    product *= left;
                    i += 2;
                    k -= 2;
                }
                else {
                    product *= right;
                    j -= 2;
                    k -= 2;
                }
            }
        }
        
        return product;
    }
};












// Pass 321/323 test cases
// class Solution {
//   public:
//     int maxSubsequenceMultiply = INT_MIN;
    
//     void solveUsingRec(vector<int>& arr, int& k, int currentProduct, int numCount, int i = 0) {
//         if(numCount == k) {
//             maxSubsequenceMultiply = maxSubsequenceMultiply > currentProduct ? maxSubsequenceMultiply : currentProduct;
//             return;
//         }
//         if(i >= arr.size()) return;
        
//         // include
//         solveUsingRec(arr, k, currentProduct * arr[i], numCount + 1, i+1);
        
//         // exclude
//         solveUsingRec(arr, k, currentProduct, numCount, i+1);
//     }
    
  
//     int maxProduct(vector<int> &arr, int k) {
//         int currentProduct = 1;
//         int numCount = 0;
//         solveUsingRec(arr, k, currentProduct, numCount, 0);
        
//         return maxSubsequenceMultiply;
//     }
// };















// Pass 320/323 test cases
// class Solution {
//   public:
//     int maxSubsequenceMultiply = INT_MIN;
    
//     void solveUsingRec(vector<int>& arr, int k, vector<int>& subSequence, int i = 0) {
//         if(subSequence.size() == k) {
//             int multiply = 1;
//             for(auto num : subSequence) multiply *= num;
//             maxSubsequenceMultiply = multiply > maxSubsequenceMultiply ? multiply : maxSubsequenceMultiply;
//             return;
//         }
//         if(i >= arr.size()) return;
        
//         // include
//         subSequence.push_back(arr[i]);
//         solveUsingRec(arr, k, subSequence, i+1);
//         subSequence.pop_back(); // backtrack
        
//         // exclude
//         solveUsingRec(arr, k, subSequence, i+1);
//     }
    
  
//     int maxProduct(vector<int> &arr, int k) {
//         vector<int> subSequence;
//         solveUsingRec(arr, k, subSequence, 0);
        
//         return maxSubsequenceMultiply;
//     }
// };