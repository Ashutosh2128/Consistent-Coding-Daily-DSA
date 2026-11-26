class Solution {
public:
    bool canAliceWin(int n) {
        for(int i = 10; i > 0; i-=2) {
            if(n >= i) {
                n -= i;
                if(n >= i-1) n -= (i-1);
                else return true;
            }
            else return false;
        }

        return true;
    }
};