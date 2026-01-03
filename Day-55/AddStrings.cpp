class Solution {
public:
    void solve(string& num1, string& num2, string& ans, int carry, int i, int j) {
        if(i < 0 && j < 0) {
            if(carry > 0)
                ans.push_back(carry + '0');

            return;
        }

        if(i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            int digit = sum % 10;
            ans.push_back(digit + '0');
            int carry = sum / 10;

            solve(num1, num2, ans, carry, i-1, j-1);
        }
        else if(i >= 0 && j < 0) {
            int sum = (num1[i] - '0') + carry;
            int digit = sum % 10;
            ans.push_back(digit + '0');
            int carry = sum / 10;

            solve(num1, num2, ans, carry, i-1, j-1);
        }
        else if(i < 0 && j >= 0) {
            int sum = (num2[j] - '0') + carry;
            int digit = sum % 10;
            ans.push_back(digit + '0');
            int carry = sum / 10;

            solve(num1, num2, ans, carry, i-1, j-1);
        }
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;

        solve(num1, num2, ans, carry, num1.length()-1, num2.length()-1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};





// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         int n1 = stoi(num1);
//         int n2 = stoi(num2);

//         int sum = n1 + n2;
//         return to_string(sum);
//     }
// };