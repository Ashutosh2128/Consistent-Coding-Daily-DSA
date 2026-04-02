class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans;
        queue<char> q;
        unordered_map<char, int> mp;
        
        for(char ch: s) {
            mp[ch]++;
            q.push(ch);
            
            while(!q.empty()) {
                if(mp[q.front()] == 1) {
                    ans.push_back(q.front());
                    break;
                }
                else q.pop();
            }
            
            if(q.empty()) ans.push_back('#');
        }
        
        return ans;
    }
};