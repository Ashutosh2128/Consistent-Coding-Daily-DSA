class Solution {
public:
    void solve(int& n, vector<int>& v, int& count, int currNum) {
        //base case
        if(currNum > n) {
            count++;
            return;
        }

        for(int i = 1; i <= n; i++) {
            if(v[i] == 0 && (i % currNum == 0 || currNum % i == 0)) {
                v[i] = currNum;

                solve(n, v, count, currNum+1);

                //backtrack
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1);
        int count = 0;

        solve(n, v, count, 1);

        return count;
    }
};