class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos;
        for(const int& it : arr) if(it >= 0) pos.push_back(it);
        
        vector<int> neg;
        for(const int& it : arr) if(it < 0) neg.push_back(it);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(j < pos.size() && k < neg.size()) {
            arr[i++] = pos[j++];
            arr[i++] = neg[k++];
        }
        
        while(j < pos.size()) arr[i++] = pos[j++];
        while(k < neg.size()) arr[i++] = neg[k++];
    }
};