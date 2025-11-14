class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        set<int> st;
        vector<int> ans;
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                st.insert(arr1[i]);
                i++;
                j++;
                k++;
            }
            else if(arr1[i] < arr2[j]) i++;
            else if(arr2[j] < arr3[k]) j++;
            else k++;
        }
        
        set<int> :: iterator it = st.begin();
        
        while(it != st.end()) {
            ans.push_back(*it);
            it++;
        }
        
        return ans;
    }
};