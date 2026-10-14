class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > (9 * num)) return "";
        // int score = 0;
        string ans = "";

        for(int i = 0; i < num; i++) {
            for(int dig = 9; dig >= 0; dig--) {
                if(sum >= dig) {
                    // score += dig * dig;
                    ans += to_string(dig);
                    sum -= dig;
                    break;
                }
            }
        }

        return ans;
    }
};