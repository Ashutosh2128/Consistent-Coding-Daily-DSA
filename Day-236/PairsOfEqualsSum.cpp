class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int, bool> mp;
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i+1; j < arr.size(); j++) {
                int sum = arr[i] + arr[j];
                if(mp.find(sum) != mp.end()) return true;
                mp[sum] = true;
            }
        }
        
        return false;
    }
};