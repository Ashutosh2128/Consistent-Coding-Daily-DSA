class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> cSumIdx;
        
        int cSum = 0;
        cSumIdx[cSum] = -1;
        int maxLen = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            cSum += arr[i];
            if(cSumIdx.find(cSum) == cSumIdx.end()) cSumIdx[cSum] = i;
            else {
                int len = i - cSumIdx[cSum];
                maxLen = maxLen < len ? len : maxLen;
            }
        }
        
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};