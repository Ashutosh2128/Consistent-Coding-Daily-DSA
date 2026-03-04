class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        s.push(arr[n-1]);
        
        vector<int> ans(n, -1);
        
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] > s.top()) ans[i] = s.top();
            else {
                while(!s.empty()) {
                    if(s.top() < arr[i]) {
                        ans[i] = s.top();
                        break;
                    }
                    else s.pop();
                }
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};