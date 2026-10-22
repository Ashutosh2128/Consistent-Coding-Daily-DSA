class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Check whether the array is already sorted
        bool isSorted = true;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                isSorted = false;
                break;
            }
        }

        if(isSorted) return 0;

        // again check wheher the array is sorted in non decreasing order
        bool isSortedDec = true;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) {
                isSortedDec = false;
                break;
            }
        }

        if(isSortedDec) return 1;

        // check the array is sorted with rotate -> every n-2 number of element decreased by 1 from its next only one increased by n-1 from its next
        int increaseCnt = 0;
        int decreaseCnt = 0;
        for(int i = 0; i < n-1; i++) {
            if((nums[i] <= nums[i+1]) && (nums[i+1] - nums[i] == 1)) increaseCnt++;
            else if((nums[i] > nums[i+1]) && (nums[i] - nums[i+1] == n-1)) decreaseCnt++;
            else break;
        }

        if((increaseCnt == n-2) && (decreaseCnt == 1)) {
            int zeroIdx;
            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) {
                    zeroIdx = i;
                    break;
                }
            }

            // there is a catch here also that if the zero Index is 2 greater than middle index instead of return the zero index value we can reverse it for 2 times and also perform ratate
            if(zeroIdx >= (n/2+2)) return 2 + (n-zeroIdx-1) + 1;
            else return zeroIdx;
        }

        // Now check array is reversed sorted woth rotate -> every n-2 number of element increase by 1 from its next, only one decrease by n-1 from its next
        decreaseCnt = 0;
        increaseCnt = 0; 
        for(int i = 0; i < n-1; i++) {
            if((nums[i] >= nums[i+1]) && (nums[i] - nums[i+1] == 1)) decreaseCnt++;
            else if((nums[i] < nums[i+1]) && (nums[i+1] - nums[i] == n-1)) increaseCnt++;
            else break;
        }

        if((decreaseCnt == n-2) && (increaseCnt == 1)) {
            int zeroIdx;
            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) {
                    zeroIdx = i;
                    break;
                }
            }

            // Here is a catch -> if zero index in before middle index then first rotate till (zeroIdx+1) then reverse, else if zero index is after or equal middle index then first reverse so the zero index get updated with n-zeroIdx-1, then rotate it with that much time
            if(zeroIdx < n/2) return 1 + (zeroIdx+1);
            else return 1 + (n-zeroIdx-1);
        }

        return -1; // sorting can't possible
    }
};