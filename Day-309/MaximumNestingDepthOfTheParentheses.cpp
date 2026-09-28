class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int depth = 0;

        for(char ch : s) {
            if(ch == '(') depth++;
            else if(ch == ')') {
                maxDepth = max(maxDepth, depth);
                depth--;
            }
        }

        return maxDepth;
    }
};