class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insert = 0;
        
        for(char ch : s) {
            if(ch == '(') {
                if(open & 1) {
                    insert++;
                    open--;
                }
                open += 2;
            }
            else {
                if(open) open--;
                else if(open == 0) {
                    open = 1;
                    insert++;
                }
            }
        }

        return open + insert;
    }
};