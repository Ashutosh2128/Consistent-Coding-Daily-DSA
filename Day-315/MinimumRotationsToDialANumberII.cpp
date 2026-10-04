class Solution {
public:
    int minRotations(int n, string s) {
        int minTotal = 0;
        int actualMinTotal;

        int firstDist = abs(0 - (s[0] - '0'));
        if(firstDist > 5) minTotal += (10 % firstDist);
        else minTotal += firstDist;

        for(int i = 0; i < n-1; i++) {
            int dist = abs((s[i] - '0') - (s[i+1] - '0'));
            if(dist > 5) minTotal += (10 % dist);
            else minTotal += dist;
        }

        actualMinTotal = minTotal;

        // Find out actual distance now let's minimize it by reversing 
        int dist1 = abs(0 - (s[0] - '0'));
        int minDist1 = dist1;
        if(dist1 > 5) minDist1 = 10 % dist1;

        int dist2 = abs(0 - (s[n-1] - '0'));
        int minDist2 = dist2;
        if(dist2 > 5) minDist2 = 10 % dist2;

        if(minDist2 < minDist1) {
            int diff = minDist1 - minDist2;
            actualMinTotal = min(actualMinTotal, minTotal - diff);
        }

        for(int k = 0; k < n-2; k++) {
            dist1 = abs((s[k] - '0') - (s[k+1] - '0'));
            minDist1 = dist1;
            if(dist1 > 5) minDist1 = 10 % dist1;
    
            dist2 = abs((s[k] - '0') - (s[n-1] - '0'));
            minDist2 = dist2;
            if(dist2 > 5) minDist2 = 10 % dist2;
    
            if(minDist2 < minDist1) {
                int diff = minDist1 - minDist2;
                actualMinTotal = min(actualMinTotal, minTotal - diff);
            }
        }

        return actualMinTotal;
    }
};