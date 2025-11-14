

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        int carry = 0;
        
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        
        string ans;
        
        while(i >= 0 && j >= 0) {
            int sum = arr1[i] + arr2[j] + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            ans.push_back(digit + '0');
            
            i--; j--;
        }
        
        while(i >= 0) {
            int sum = arr1[i] + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            ans.push_back(digit + '0');
            
            i--;
        }
        
        while(j >= 0) {
            int sum = arr2[j] + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            ans.push_back(digit + '0');
            
            j--;
        }
        
        if(carry) ans.push_back(carry + '0');
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};