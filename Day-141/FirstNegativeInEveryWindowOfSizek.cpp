class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        queue<int> q;
        vector<int> ans;
        
        //Process first wondow
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) q.push(i);
        }
        
        //Process remaining window
        for(int i = k; i < n; i++) {
            //step-1: findout answer
            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
            
            //removal operation
            if(!q.empty() && i - q.front() == k) q.pop();
            
            //addition
            if(arr[i] < 0) q.push(i);
        }
        
        //Process last window
        if(q.empty()) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        
        return ans;
    }
};