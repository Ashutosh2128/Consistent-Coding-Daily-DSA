class Solution {
public:
    bool isPossibleEatingSpeed(vector<int>& piles, int h, int k) {
        long long int totalHour = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalHour += ceil(piles[i] / double(k));
        }

        if(totalHour <= h) return true;

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int minEatSpeed = 1;
        int maxEatSpeed = *max_element(piles.begin(), piles.end());

        int ans = 0;

        while(minEatSpeed <= maxEatSpeed) {
            int mid = minEatSpeed + (maxEatSpeed - minEatSpeed) / 2;

            if(isPossibleEatingSpeed(piles, h, mid)) {
                ans = mid;
                maxEatSpeed = mid - 1;
            }
            else minEatSpeed = mid + 1;
        }

        return ans;
    }
};