class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool isSorted = true;

        for(int i = 0; i < n-1; i++) {
            if(s[i] > s[i+1]) {
                isSorted = false;
                break;
            }
        }

        if(isSorted) return 0;
        if(n == 2) return -1;
        
        char min = *min_element(s.begin(), s.end());
        char max = *max_element(s.begin(), s.end());

        if(s[0] == min || s[n-1] == max) return 1;
        for(int i = 1; i < n-1; i++) if(s[i] == min || s[i] == max) return 2;
        return 3;
    }
};