class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < a.size(); i++) mp[a[i]]++;
        
        for(int i = 0; i < b.size(); i++) {
            int num = b[i];
            if(mp.find(num) != mp.end() && mp[num] >= 1) mp[num]--;
            else return false;
        }
        
        return true;
    }
};