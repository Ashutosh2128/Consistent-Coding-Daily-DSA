class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int>& sides, int i) {
        if(i >= matchsticks.size()) {
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
        }

        bool ans = false;
        for(int j = 0; j < sides.size(); j++) {
            if(matchsticks[i] <= sides[j]) {
                sides[j] -= matchsticks[i];
                ans = ans || solve(matchsticks, sides, i+1);
                if(ans) return true;
                sides[j] += matchsticks[i];
            }
        }

        return ans;
    }

    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;

        int sideSum = sum / 4;

        vector<int> sides(4, sideSum);

        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, sides, 0);
    }
};