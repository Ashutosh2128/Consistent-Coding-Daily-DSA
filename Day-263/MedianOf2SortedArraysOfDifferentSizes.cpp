class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        vector<int> merge;
        
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) merge.push_back(a[i++]);
            else merge.push_back(b[j++]);
        }
        
        while(i < a.size()) merge.push_back(a[i++]);
        while(j < b.size()) merge.push_back(b[j++]);
        
        if(merge.size() % 2 == 0) {
            int mid = merge.size() / 2;
            return (merge[mid] + merge[mid-1])/2.0;
        }
        else return merge[merge.size()/2];
    }
};