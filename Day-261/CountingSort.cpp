class Solution {
  public:
    string countSort(string s) {
        char maxCh = 'a';
        for(char ch : s) if(ch > maxCh) maxCh = ch;
        
        vector<int> arr(maxCh - 'a' + 1, 0);
        
        for(char ch : s) arr[ch - 'a']++;
        
        string ans = "";
        for(int i = 0; i < arr.size(); i++) {
            while(arr[i]) {
                ans.push_back('a' + i);
                arr[i]--;
            }
        }
        
        return ans;
    }
};