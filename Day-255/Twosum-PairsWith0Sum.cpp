class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int s = 0;
        int e = arr.size()-1;
        vector<vector<int>> ans;
        
        while(s < e) {
            int sum = arr[s] + arr[e];
            
            if(sum == 0) {
                ans.push_back({arr[s], arr[e]});
                while(arr[s] == arr[s+1]) s++;
                while(arr[e] == arr[e-1]) e--;
                s++;
                e--;
            }
            else if(sum < 0) s++;
            else e--;
        }
        
        return ans;
    }
};