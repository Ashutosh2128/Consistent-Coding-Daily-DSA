class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> s;
        int n = mat.size();
        
        for(int i = 0; i < n; i++) s.push(i);
        
        while(s.size() != 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            if(mat[a][b]) //means a knows b
                s.push(b);
            else // means b knows a
                s.push(a);
        }
        
        if(s.empty()) return -1;
        
        int mightCelebrity = s.top(); s.pop();
        
        for(int i = 0; i < n; i++) {
            if(i!= mightCelebrity && mat[mightCelebrity][i] != 0) return -1;
        }
        
        for(int i = 0; i < n; i++) {
            if(mat[i][mightCelebrity] == 0 && i != mightCelebrity) return -1;
        }
        
        return mightCelebrity;
    }
};