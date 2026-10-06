class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // First we calculate and store left product of all element in ans vector
        int leftProduct = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Then calculate right product and multiply with current ans element reversly
        int rightProduct = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] = ans[i] * rightProduct;
            rightProduct *= nums[i];
        }

        // Now we have calculate and store all the product of all element except the particular element
        return ans;
    }
};








// this required O(N) TC and O(N) SC also
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> leftProd(n);
//         int product = 1;
//         for(int i = 0; i < n; i++) {
//             leftProd[i] = product;
//             product *= nums[i];
//         }

//         vector<int> rightProd(n);
//         product = 1;
//         for(int i = n-1; i >= 0; i--) {
//             rightProd[i] = product;
//             product *= nums[i];
//         }

//         vector<int> ans(n);
//         for(int i = 0; i < n; i++) ans[i] = leftProd[i] * rightProd[i];

//         return ans;
//     }
// };