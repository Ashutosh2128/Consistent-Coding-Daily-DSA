class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(arr[0]);
        
        for(int i = 1; i < n; i++) {
            if(s.top() < arr[i]) ans[i] = s.top();
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