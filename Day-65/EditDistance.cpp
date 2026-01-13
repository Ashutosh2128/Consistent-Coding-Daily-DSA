class Solution {
public:
    int solve(string w1, string w2, int i, int j) {
        //base cases
        if(i >= w1.length()) return w2.length() - j;

        if(j >= w2.length()) return w1.length() - i;

        int ans = 0;
        if(w1[i] == w2[j]) ans = solve(w1, w2, i+1, j+1);
        else {
            //insert
            int opt1 = 1 + solve(w1, w2, i, j+1);

            //delete
            int opt2 = 1 + solve(w1, w2, i+1, j);

            //update
            int opt3 = 1 + solve(w1, w2, i+1, j+1);

            ans = min(opt1, min(opt2, opt3));
        }

        return ans;
    }

    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};