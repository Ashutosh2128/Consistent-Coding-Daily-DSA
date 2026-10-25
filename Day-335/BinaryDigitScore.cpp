class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0;
        while(a) {
            if(a & 1) s1++;
            a = a >> 1;
        }

        int s2 = 0;
        while(b) {
            if(b & 1) s2++;
            b = b >> 1;
        }

        if(s1 >= s2) return s1 * s2;
        return s2 / s1;
    }
};