class Solution {
public:
    int minRange(int a, int b, int c) {
        int range = INT_MAX;

        int maxi = max(a, max(b, c));
        int mini = min(a, min(b, c));
        int mid = a + b + c - maxi - mini;

        int diff = maxi - mini;
        range = min(range, diff);
        
        while((mini + mid) != maxi) {
            maxi = mini + mid;
            diff = maxi - mini;
            range = min(range, diff);
        }

        return range;
    }
};