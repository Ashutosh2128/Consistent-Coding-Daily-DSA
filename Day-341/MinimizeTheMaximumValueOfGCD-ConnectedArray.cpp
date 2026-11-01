class Solution {
public:
    int findSPF(int num) {
        for(int i = 2; 1LL * i * i < num; i++) if(num % i == 0) return i;
        return num;
    }
    
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        
        int leftReq = index;
        int rightReq = n - index - 1;

        long long minLast = -1;
        
        if(value & 1) {
            //odd
            int spf = findSPF(value);
            if(leftReq && (value - (spf + 2LL * (leftReq - 1)) <= 0)) return -1;
            if(rightReq == 0) return value;
            minLast = value + (spf + 2LL * (rightReq - 1));
        }
        else {
            //even
            if(leftReq && value - 2LL * leftReq <= 0) return -1;
            if(rightReq == 0) return value;
            minLast = value + 2LL * rightReq;
        }

        return minLast;
    }
};